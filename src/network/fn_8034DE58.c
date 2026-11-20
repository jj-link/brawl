#include <types.h>
#include <revolution/OS/OSTime.h>
#include <revolution/DWC/dwc_main.h>
#pragma force_active on

typedef struct S {
    char p0[0xD];
    u8 f0D;
    char p0E[8];
    u8 f16;
    u8 f17;
    char p18[8];
    u32 f20;
    u32 f24;
    char p28[0x10];
    u32 f38;
    char p3c[0x7C];
    u16 fB8;
    char pBA[0x4E];
    s32 f108[43];
    s32 f1B4;
    char p1B8[0x60];
    s32 f218;
    char p21c[0xCC];
    u8 f2E8[1];
} S;

extern S *lbl_805A0FA8;
extern s32 fn_80335238(void);
extern s32 fn_8034D940(u8, u32, u32);
extern s64 fn_803F1470(s64, s64);
extern u8 fn_8033A77C(void);
extern s32 fn_803437E4(u32, u32, u16, void *, u32);
extern s32 fn_80349C88(void);
extern s32 fn_80349F28(s32);

#define SWAP32(x) \
    (((((((u32)(x) >> 8) & 0xFF0000u) | (((u32)(x) >> 8) & 0xFFu)) | \
       ((((u32)(x) << 8) & 0xFF000000u) | (((u32)(x) << 8) & 0xFF00u))) << 16) | \
     ((((((u32)(x) >> 8) & 0xFF0000u) | (((u32)(x) >> 8) & 0xFFu)) | \
       ((((u32)(x) << 8) & 0xFF000000u) | (((u32)(x) << 8) & 0xFF00u))) >> 16))

#define SWAP32R(x) \
    (((((((u32)(x) >> 8) & 0xFF0000u) | (((u32)(x) >> 8) & 0xFFu)) | \
       ((((u32)(x) << 8) & 0xFF000000u) | (((u32)(x) << 8) & 0xFF00u))) >> 16) | \
     ((((((u32)(x) >> 8) & 0xFF0000u) | (((u32)(x) >> 8) & 0xFFu)) | \
       ((((u32)(x) << 8) & 0xFF000000u) | (((u32)(x) << 8) & 0xFF00u))) << 16))

static inline u8 lookup(void) {
    S *b = lbl_805A0FA8;
    s32 count = b->f0D;
    s32 i;
    s32 val = b->f218;
    for (i = 0; i <= count; i++) {
        if (val == b->f108[i]) {
            return lbl_805A0FA8->f2E8[i];
        }
    }
    return 0xFF;
}

static inline s32 send(void *data, u32 arg0) {
    u32 *pb = data;
    S *s = lbl_805A0FA8;
    u32 w = s->f218;
    u32 v;
    pb[1] = 0;
    pb[0] = SWAP32(w);
    pb[2] = SWAP32(arg0);
    v = fn_8033A77C();
    pb[3] = SWAP32R(v);
    return fn_803437E4(0x82, lbl_805A0FA8->f38, lbl_805A0FA8->fB8, pb, 4);
}

s32 fn_8034DE58(u32 arg0) {
    u32 buf[4];
    u64 now;
    s64 q;
    s32 r;
    S *p;

    if (fn_80335238() != 0 || lbl_805A0FA8 == 0 || lbl_805A0FA8->f17 == 0 ||
        (DWC_GetState() != 5 && DWC_GetState() != 6) ||
        (p = lbl_805A0FA8, p->f17 == 0) ||
        (p->f1B4 != 0xF && p->f1B4 != 1)) {
        return 0;
    }

    if ((s32)p->f17 == 2) {
        return fn_8034D940(lookup(), arg0, 0);
    }

    now = OSGetTime();
    q = fn_803F1470((s64)(now - *(u64 *)&p->f20),
                    (s64)((*(u32 *)0x800000F8 >> 2) / 1000));
    if (q > 3000) {
        r = send(buf, arg0);
        if (lbl_805A0FA8->f16 == 0) {
            r = fn_80349F28(r);
        } else {
            r = fn_80349C88();
        }
        if (r != 0) return 0;
        *(u64 *)&lbl_805A0FA8->f20 = OSGetTime();
    }
    return 1;
}
