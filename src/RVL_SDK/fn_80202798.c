#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern s32 fn_80202F70(void *);
extern void fn_802030E4(void *);
extern void fn_80203208(void *);
extern s32 fn_8020331C(void *);
extern char lbl_8047B140[];
extern char lbl_8047B200[];
extern f32 lbl_805A3918;
extern f32 lbl_805A391C;

s32 fn_80202798(void *arg0)
{
    char *p;
    BOOL r31;
    BOOL r29;
    f32 f;
    f32 threshold;
    p = (char *)arg0;
    r31 = OSDisableInterrupts();
    f = *(f32 *)(p + 0x114);
    if ((*(s32 *)(p + 0x10C) = 1) && f < 0.0f) {
        r29 = OSDisableInterrupts();
        *(u32 *)(p + 0x10C) |= 1;
        fn_80203208(arg0);
        OSRestoreInterrupts(r29);
        OSRestoreInterrupts(r31);
        return 0;
    }
    f = lbl_805A3918 * f;
    *(s32 *)(p + 0x1C) = *(s32 *)(lbl_8047B140 + 0x5C);
    *(u32 *)(p + 0x40) = (u32)f;
    *(s32 *)(p + 0x80) = *(s32 *)(lbl_8047B200 + 0xC0);
    *(s32 *)(p + 0x84) = *(s32 *)(lbl_8047B200 + 0xC4);
    *(s32 *)(p + 0x88) = *(s32 *)(lbl_8047B200 + 0xC8);
    *(s32 *)(p + 0xC0) = *(s32 *)(lbl_8047B200 + 0xCC);
    *(s32 *)(p + 0xC4) = *(s32 *)(lbl_8047B200 + 0xD0);
    *(s32 *)(p + 0xEC) = *(s32 *)(lbl_8047B200 + 0xD4);
    *(s32 *)(p + 0xF0) = *(s32 *)(lbl_8047B200 + 0xD8);
    *(s32 *)(p + 0xF4) = *(s32 *)(lbl_8047B200 + 0xDC);
    if (fn_80202F70(arg0) == 0) {
        r29 = OSDisableInterrupts();
        *(u32 *)(p + 0x10C) |= 1;
        fn_80203208(arg0);
        OSRestoreInterrupts(r29);
        OSRestoreInterrupts(r31);
        return 0;
    }
    fn_802030E4(arg0);
    if (fn_8020331C(arg0) == 0) {
        r29 = OSDisableInterrupts();
        *(u32 *)(p + 0x10C) |= 1;
        fn_80203208(arg0);
        OSRestoreInterrupts(r29);
        OSRestoreInterrupts(r31);
        return 0;
    }
    *(u32 *)(p + 0x10C) &= ~1;
    OSRestoreInterrupts(r31);
    return 1;
}
