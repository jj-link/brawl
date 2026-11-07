#include <types.h>
#pragma force_active on

s32 fn_80398BD8(void *, s32, s32);
s32 fn_8039FB14(void *, s32, s32 *);
s32 fn_8039FC78(void *, s32, s32 *);
extern s32 lbl_805A1190;

s32 fn_8039FA54(u8 *self) {
    s32 sp8;
    s32 ret;

    if (*(s32 *)(self + 0x4C) == 0) {
        return -5;
    }
    switch (*(s32 *)(self + 0x64)) {
    case 0:
    case 1:
        ret = fn_80398BD8(*(void **)(self + 0x48), *(s32 *)(self + 0x4C), lbl_805A1190);
        sp8 = *(s32 *)(self + 0x4C);
        break;
    case 2:
        ret = fn_8039FB14(*(void **)(self + 0x48), *(s32 *)(self + 0x4C), &sp8);
        break;
    case 3:
        ret = fn_8039FC78(*(void **)(self + 0x48), *(s32 *)(self + 0x4C), &sp8);
        break;
    default:
        ret = -3;
        break;
    }
    if (ret == 0) {
        *(s32 *)(self + 0xE8) = *(s32 *)(self + 0x4C);
        *(s32 *)(self + 0x8) = *(s32 *)(self + 0x8) + sp8;
    }
    return ret;
}
