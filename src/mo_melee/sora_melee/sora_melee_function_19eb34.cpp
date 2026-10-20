#include <types.h>
#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_CDA70(void* self, int flag);

struct fn_27_19EB34_Obj {
    u8 m_pad[0xC];
};

void* fn_27_19EB34(fn_27_19EB34_Obj* self, int flag) {
    if (self) {
        __destroy_arr((u8*)self + 0xC, fn_27_CDA70, 0x10, 1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
