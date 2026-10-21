#pragma force_active on
#include <types.h>

extern "C" void* memcpy(void*, const void*, unsigned long);

extern "C" int fn_800345D8(void* arg0, unsigned char arg1, void* arg2) {
    int temp_r6 = *(int*)((u8*)arg0 + 0x8C);
    if (temp_r6 == 0 || (u32)*(u16*)((u8*)arg0 + 0x90) <= (u32)arg1) {
        return 0;
    }
    memcpy((void*)(temp_r6 + arg1 * 0x60), arg2, 0x4C);
    return 1;
}
