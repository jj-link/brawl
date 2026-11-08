#include <types.h>
#include <mv/mv_THPPlayer.h>
#pragma force_active on
extern "C" s32 fn_8025C138(s32, s32, s32, s32, s32);
extern "C" s32 fn_8007E88C(char* arg0) {
    char* flag_ptr;
    s32* data;
    u32 i;
    u32* sizes;
    sizes = (u32*)(arg0 + 8);
    data = (s32*)*(void**)((char*)&g_thpObject + 0xE8);
    i = 0;
    flag_ptr = (char*)&g_thpObject;
    u8* data_ptr = (u8*)arg0 + (g_thpObject.unk6C.length << 2) + 8;
    while (i < g_thpObject.unk6C.length) {
        switch (((u8*)flag_ptr)[0x70]) {
        default: break;
        case 0:
            s32 result = fn_8025C138((s32)data_ptr, data[0], data[1], data[2], *(s32*)((char*)&g_thpObject + 0x9C));
            *(s32*)((char*)&g_thpObject + 0xAC) = result;
            if (result != 0) return 0;
        }
        data_ptr += *sizes;
        sizes++;
        flag_ptr++;
        i++;
    }
    return 1;
}