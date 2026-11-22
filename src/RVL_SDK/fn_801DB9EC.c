#include <types.h>
#include <string.h>
#include <revolution/GX/GXTypes.h>
#include <revolution/OS/OSCache.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSError.h>
#include <revolution/BASE/PPCArch.h>
#pragma force_active on

extern u8 lbl_804DD4E8[];
extern char lbl_8059E9D8[4];
extern void fn_801DCF24(void);
extern void *fn_801D718C(int, int);
extern u32 fn_801D7154(void);
extern void *fn_803F602C(void *, const void *, u32);
extern int fn_801DC698(void *, u32);
extern void fn_801E99C4(void *);
extern void fn_801DB6EC(int, int);
extern void fn_801E98B0(void);
extern s32 fn_801E9AA8(void);
extern void fn_801DB3C8(u8 *, u16, u16, const u8 *, s32, s32, u32, const char *);
extern void fn_801E9A30(int);

extern const f32 lbl_805A3704, lbl_805A3708, lbl_805A3700, lbl_805A36FC, lbl_805A36F8, lbl_805A3714, lbl_805A3718, lbl_805A3710, lbl_805A370C, lbl_805A371C, lbl_805A3720, lbl_805A3724, lbl_805A3728;

typedef struct FatalParam {
    GXColor textColor;
    GXColor bgColor;
    const char *msg;
} FatalParam;

static inline GXColor RGB2YUV(GXColor rgb) {
    GXColor yuv;
    f32 y = (lbl_805A3704 * rgb.r + lbl_805A3708 * rgb.g + lbl_805A3700 * rgb.b + lbl_805A36FC) + lbl_805A36F8;
    f32 cb = (lbl_805A3714 * rgb.r - lbl_805A3718 * rgb.g + lbl_805A3710 * rgb.b + lbl_805A370C) + lbl_805A36F8;
    f32 cr = (lbl_805A3710 * rgb.r - lbl_805A371C * rgb.g - lbl_805A3720 * rgb.b + lbl_805A370C) + lbl_805A36F8;
    yuv.r = y > lbl_805A3724 ? lbl_805A3724 : y < lbl_805A36FC ? lbl_805A36FC : y;
    yuv.g = cb > lbl_805A3728 ? lbl_805A3728 : cb < lbl_805A36FC ? lbl_805A36FC : cb;
    yuv.b = cr > lbl_805A3728 ? lbl_805A3728 : cr < lbl_805A36FC ? lbl_805A36FC : cr;
    yuv.a = 0;
    return yuv;
}
static inline void ScreenClear(u8 *fb, u16 width, u16 height, GXColor yuv) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x += 2) {
            fb[0] = yuv.r;
            fb[1] = yuv.g;
            fb[2] = yuv.r;
            fb[3] = yuv.b;
            fb += 4;
        }
    }
}

static inline void ScreenReport(u8 *fb, GXColor yuv, u8 *font, FatalParam *params) {
    fn_801DB3C8(fb, 640, 480, (const u8 *)&yuv, 48, 100, *(u16 *)(font + 14), params->msg);
}

void fn_801DB9EC(void) {
    s32 retraceCount;
    u8 *msgFont;
    u8 *fb;
    void *msgBuf;
    const char *msg;
    size_t msgLen;
    FatalParam *params;

    fn_801DCF24();
    params = (FatalParam *)lbl_804DD4E8;
    msg = params->msg;
    msgLen = strlen(msg) + 1;
    msgBuf = fn_801D718C(msgLen, 32);
    params->msg = fn_803F602C(msgBuf, msg, msgLen);
    msgFont = fn_801D718C(0xA1004, 32);
    fn_801DC698(msgFont, fn_801D7154());
    fb = fn_801D718C(0x96000, 32);
    ScreenClear(fb, 640, 480, RGB2YUV(params->bgColor));
    fn_801E99C4(fb);
    fn_801DB6EC(640, 480);
    fn_801E98B0();
    retraceCount = fn_801E9AA8();
    while (fn_801E9AA8() - retraceCount < 2) {}
    ScreenReport(fb, RGB2YUV(params->textColor), msgFont, params);
    DCFlushRange(fb, 0x96000);
    fn_801E9A30(0);
    fn_801E98B0();
    retraceCount = fn_801E9AA8();
    while (fn_801E9AA8() - retraceCount < 1) {}
    OSDisableInterrupts();
    OSReport(lbl_8059E9D8, params->msg);
    PPCHalt();
}
