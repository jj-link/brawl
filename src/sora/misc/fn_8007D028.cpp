#include <types.h>
#pragma force_active on

extern char g_thpObject[];

extern "C" void fn_8007B4A4(void);
extern "C" void fn_8007B5BC(void);
extern "C" void fn_8007BAC8(int a0, int a1, int a2, s16 a3, s16 a4, int a5, int a6, s16 a7, s16 a8);

extern "C" s32 fn_8007D028(int a0, int a1, int arg2, int arg3, int arg4, int arg5) {
    if (*(int*)(g_thpObject + 0xA0) != 0 && *(u8*)(g_thpObject + 0xA4) != 0 && *(int*)(g_thpObject + 0xE8) != 0) {
        fn_8007B5BC();
        char* p = *(char**)(g_thpObject + 0xE8);
        fn_8007BAC8(*(int*)(p + 0), *(int*)(p + 4), *(int*)(p + 8), arg2, arg3, (s16)*(int*)(g_thpObject + 0x80), (s16)*(int*)(g_thpObject + 0x84), arg4, arg5);
        fn_8007B4A4();
        p = *(char**)(g_thpObject + 0xE8);
        return (s32)((*(u32*)(p + 0xC) + *(u32*)(g_thpObject + 0xC0)) % *(u32*)(g_thpObject + 0x50));
    }
    return -1;
}
