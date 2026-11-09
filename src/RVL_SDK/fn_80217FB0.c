#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;
typedef long long s64;
typedef unsigned long long u64;

extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern u64 fn_801E1B54(void);
extern void fn_801EA078(void);
extern s32 fn_802172F8(void *, void *, void *);
extern void fn_80217EA4(s32);
extern void fn_8021A68C(s32, s32, void *);
extern s64 fn_803F1470(s32, u32, s32, u32);
extern void *memcpy(void *, const void *, u32);
extern void *memset(void *, s32, u32);
extern void fn_80219F3C(void);
extern int lbl_804F6810[];
extern u8 lbl_805A0C7A;

void fn_80217FB0(s32 arg0)
{
    u8 *st;
    u8 *st2;
    s32 var_r28;
    s32 intr;
    u8 *src;
    s32 r;
    s32 intr2;
    u64 t;
    s64 d;
    u8 z;

    st = (u8 *)lbl_804F6810[arg0];
    var_r28 = 0;
    if (*(s32 *)(st + 0x8BC) != -1) {
        intr = OSDisableInterrupts();
        z = (u8)(*(u8 *)(st + 0x8C8) == 0);
        src = st + 0xA0 + z * 0x60;
        r = fn_802172F8(st, src, st + 0x40);
        if (r != 0) {
            memcpy(st + 0x40, src, 0x60);
        }
        if (*(s8 *)(st + 0x69) != 0) {
            memset(st + 0x40, 0, 0x60);
        }
        OSRestoreInterrupts(intr);
        fn_80217EA4(arg0);
        if (r != 0) {
            var_r28 = 1;
            t = fn_801E1B54();
            *(u32 *)(st + 0x8F4) = (u32)t;
            *(u32 *)(st + 0x8F0) = (u32)(t >> 32);
        } else if (lbl_805A0C7A != 0) {
            t = fn_801E1B54();
            d = (s64)t - (s64)(((u64)*(u32 *)(st + 0x8F0) << 32) |
                                *(u32 *)(st + 0x8F4));
            if ((s32)fn_803F1470((s32)(d >> 32), (u32)d, 0,
                                 *(u32 *)0x800000F8 >> 2) >
                (s32)(lbl_805A0C7A * 0x3C)) {
                st2 = (u8 *)lbl_804F6810[arg0];
                intr2 = OSDisableInterrupts();
                r = *(s32 *)(st2 + 0x8BC);
                OSRestoreInterrupts(intr2);
                if (r != -1) {
                    intr2 = OSDisableInterrupts();
                    if (*(u8 *)(st2 + 0x986) != 0) {
                        OSRestoreInterrupts(intr2);
                    } else {
                        *(u8 *)(st2 + 0x986) = 1;
                        OSRestoreInterrupts(intr2);
                        fn_8021A68C(arg0, 0, (void *)fn_80219F3C);
                    }
                }
            }
        }
        if (var_r28 != 0) {
            fn_801EA078();
        }
    }
}
