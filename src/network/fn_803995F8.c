#pragma force_active on
#include <types.h>

typedef struct {
    u32 unk0;
    u32 unk4;
} Pair;

typedef struct {
    u8 pad0[8];
    u32 unk8;
    u32 unkC;
} Src;

extern s32 fn_8039A260(void);
extern s32 fn_8039A274(void);
extern s32 fn_8039A29C(s32);
extern s32 fn_803A072C(void);
extern s32 fn_803A07FC(void);
extern s32 fn_803A0BE8(Pair *, s32 *);
extern s32 fn_803A1FF0(void);
extern void fn_801D7718(void *, u32);
extern Src *lbl_805A1168;

static inline s32 generate_id(Pair *arg0) {
    s32 sp8;
    s32 r31;
    s32 ret;
    s32 tmp;
    ret = fn_8039A29C(1);
    if (ret < 0) return ret;
    sp8 = 0;
    if (arg0 == 0) {
        r31 = -3;
    } else {
        arg0->unk4 = 0x6FC0FFFF;
        arg0->unk0 = 0x2386F2;
        ret = fn_803A0BE8(arg0, &sp8);
        r31 = ret;
        *(u64 *)0x800031C0 = *(u64 *)arg0;
        fn_801D7718((void *)0x800031C0, 0x20);
    }
    tmp = fn_8039A29C(0);
    if (r31 >= 0) r31 = tmp;
    return r31;
}

s32 fn_803995F8(Pair *arg0) {
    s32 sp8;
    s32 r31;
    s32 ret;
    s32 tmp;
    u32 a;
    u32 b;
    u32 t0;
    u32 t4;

    r31 = 0;
    if (fn_8039A260() != 0 || fn_8039A274() != 0) {
        *(u64 *)arg0 = *(u64 *)&lbl_805A1168->unk8;
        goto block_end;
    }
    *(u64 *)arg0 = *(u64 *)0x800031C0;
    if (*(u64 *)arg0 == 0) {
        ret = -5;
    } else {
        ret = fn_803A1FF0();
    }
    if (ret == 0) {
        return ret;
    }
    ret = fn_803A072C();
    if (ret < 0) {
        return ret;
    }
    ret = generate_id(arg0);
    r31 = ret;
    if ((u32)(ret + 0x24) <= 1) {
        r31 = 0;
    }
    tmp = fn_803A07FC();
    if (tmp < 0) {
        if (r31 != 0) {
            tmp = r31;
        }
        r31 = tmp;
    }
block_end:
    return r31;
}
