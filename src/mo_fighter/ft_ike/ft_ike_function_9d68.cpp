#include <types.h>
#pragma force_active on

extern "C" s32 fn_119_9D5C();

extern "C" s32 fn_119_9D68(u8* base, s32 unused, s32 i, s32 j) {
    s32* arr = *(s32**)((base - 0x10000) + fn_119_9D5C() * 0x2c + i * 4 - 0x7570);
    return arr[j];
}
