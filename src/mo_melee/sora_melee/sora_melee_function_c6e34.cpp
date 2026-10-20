#include <types.h>
#pragma force_active on

extern "C" void fn_27_C6E34(u8* self, u8* a, void* b) {
    if (self[0x8E] != 0) {
        return;
    }
    void* p = *(void**)(a + 8);
    *(void**)(self + 0x44) = *(void**)((u8*)p + 0x28);
    *(u8**)(self + 0x48) = a;
    *(void**)(self + 0x4C) = b;
    self[0x8C] = 1;
}
