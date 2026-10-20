#include <types.h>
#pragma force_active on

extern "C" void* fn_8015C1D0(void* a, int b);
extern "C" void fn_8015C144(void* a, void* b);

extern "C" {
void* fn_27_36D0(char* self, int index);
}

extern "C" void* fn_27_36D0(char* self, int index) {
    u32 off = index * 12;
    void* r = fn_8015C1D0(self + off, 0);
    fn_8015C144(self + (index * 12), r);
    return r;
}
