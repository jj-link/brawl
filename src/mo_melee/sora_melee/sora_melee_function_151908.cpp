#include <types.h>
#pragma force_active on

extern "C" {
void* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(void* self, u32 a, u32 b);

u32 fn_27_151908(void* unused, void* acc, u32 idx) {
    void* p = getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0x10000 - 0x57FD, 0);
    u32* base = *(u32**)p;
    u32 v = *(u32*)((u8*)base + (idx << 5) + 0x1c);
    return (v >> 19) & 3;
}
}
