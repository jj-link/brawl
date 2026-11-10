#include <mv/mv_THPPlayer.h>
#include <types.h>
#pragma force_active on

extern "C" s32 fn_801E9AB0(void);
extern "C" u32 fn_801E9BDC(f32);
extern "C" s64 fn_803F1470(s64, s64);
extern "C" f32 lbl_805A1B50;

extern "C" s32 fn_8007CF00(void) {
    char* p = (char*)&g_thpObject;
    s32 flag = *(s32*)(p + 0x88);
    if (flag & 1) {
        if (fn_801E9AB0() == 0) {
            return 1;
        }
        goto done;
    }
    if (flag & 2) {
        if ((u32)fn_801E9AB0() == 1) {
            return 1;
        }
        goto done;
    }
    s32 t = (s32)(lbl_805A1B50 * *(f32*)(p + 0x4C));
    if (fn_801E9BDC(lbl_805A1B50) == 1) {
        u64 x = ((u64)*(u32*)(p + 0xC8) << 32) | *(u32*)(p + 0xCC);
        *(u32*)(p + 0xD4) = (u32)fn_803F1470((s64)(x * (s64)t), 5000);
    } else {
        u64 x = ((u64)*(u32*)(p + 0xC8) << 32) | *(u32*)(p + 0xCC);
        *(u32*)(p + 0xD4) = (u32)fn_803F1470((s64)(x * (s64)t), 5994);
    }
    if (*(s32*)((char*)&g_thpObject + 0xD0) != *(s32*)((char*)&g_thpObject + 0xD4)) {
        *(s32*)((char*)&g_thpObject + 0xD0) = *(s32*)((char*)&g_thpObject + 0xD4);
        return 1;
    }
done:
    return 0;
}
