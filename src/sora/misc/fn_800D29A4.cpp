#include <types.h>
#include <string.h>
#pragma force_active on

extern "C" void* memset(void*, int, unsigned long);

struct T {
    u8 pad[0x1a8];
    u8 field[0x28];
    u8 pad2[0x48];
};

extern "C" s32 fn_800D29A4(u8* base, s32 arg1, s32 arg2, u8* src_) {
    T* t = (T*)base;
    u8* dest = t[arg1].field + arg2 * 0x28;
    u8* src = src_;
    s32 count = 0x14;
    memset(dest, 0, 0x28);
    s32 result;
    while (--count >= 0) {
        result = src[0];
        u8 hi = src[1];
        src += 2;
        dest[0] = result;
        result = result | hi;
        dest[1] = hi;
        dest += 2;
        if (result == 0) {
            break;
        }
    }
    return result;
}
