#include <revolution/OS/OSCache.h>
#pragma force_active on

typedef struct Ctx {
    u8 pad0[0x480];
    s32 unk480;
    s16 *unk484;
    s32 unk488;
    s16 unk48C;
    s16 unk48E;
    void (*unk490)(void);
} Ctx;

extern Ctx *lbl_805A0750;
extern f32 lbl_805A3740;
extern f64 lbl_805A3748;
extern u32 fn_801FECB8(void);
extern void fn_801D76BC(void *address, u32 length);
extern u32 fn_801FECD0(void);
extern void fn_801FEC04(void *dst, u32 size);

void fn_801E3948(void) {
    void (*callback)(void);
    f32 scale;

    callback = lbl_805A0750->unk490;
    if (callback != NULL) {
        callback();
    }

    if (lbl_805A0750->unk488 == 0) {
        lbl_805A0750->unk484 = (s16 *)(fn_801FECB8() + 0x80000000);
    }

    if ((u32)lbl_805A0750->unk488 == 1) {
        fn_801D76BC(lbl_805A0750->unk484, 4);
        lbl_805A0750->unk48C = *lbl_805A0750->unk484++;
        lbl_805A0750->unk48E = *lbl_805A0750->unk484;
    }

    if ((u32)lbl_805A0750->unk488 >= 1) {
        char *base;
        char *dst;
        u32 size;
        s32 remaining;

        base = (char *)lbl_805A0750 + lbl_805A0750->unk480 * 0x240;
        dst = base;
        size = fn_801FECD0();
        scale = lbl_805A3740;
        remaining = (s32)size;
        while (remaining != 0) {
            remaining -= 4;
            *(s16 *)dst = lbl_805A0750->unk48C;
            *(s16 *)(dst + 2) = lbl_805A0750->unk48E;
            dst += 4;
            lbl_805A0750->unk48C = (s16)((f32)lbl_805A0750->unk48C * scale);
            lbl_805A0750->unk48E = (s16)((f32)lbl_805A0750->unk48E * scale);
        }
        DCFlushRange(base, size);
        fn_801FEC04(base, size);
        lbl_805A0750->unk480 = lbl_805A0750->unk480 + 1;
        lbl_805A0750->unk480 &= 1;
    }

    lbl_805A0750->unk488 = lbl_805A0750->unk488 + 1;
}
