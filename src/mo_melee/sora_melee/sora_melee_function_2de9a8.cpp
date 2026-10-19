#include <types.h>
#pragma force_active on

extern "C" void fn_27_2E0784(void* a, void* b, void* c);

extern "C" bool fn_27_2DE9A8(void* unused, void* a, void* b, void* c) {
    void* p = *(void**)((u8*)b + 0x8);
    void* q = *(void**)((u8*)p + 0x28);
    fn_27_2E0784(a, q, c);
    return true;
}
