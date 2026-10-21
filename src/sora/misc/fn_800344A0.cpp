#include <types.h>
#pragma force_active on

extern "C" u64 fn_800344A0(void* self, u32 index) {
    u32 arr = *(u32*)((u8*)self + 0x7C);
    u32 hi, lo;
    lo = 0;
    hi = 0;
    if (arr != 0) {
        u16 count = *(u16*)((u8*)self + 0x82);
        if (count > index) {
            u8* elem = (u8*)arr + index * 0x2020;
            hi = *(u32*)(elem + 0x2000);
            lo = *(u32*)(elem + 0x2004);
        }
    }
    return ((u64)hi << 32) | lo;
}
