#include <types.h>
#pragma force_active on

extern "C" void fn_27_A6978(void* p, int n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);

struct fn_27_Obj {
    u8 m_pad[0xC];
};

extern "C" {
fn_27_Obj* fn_27_198E00(fn_27_Obj* self, int flag) {
    if (self) {
        __destroy_arr((char*)self + 0xC, fn_27_A6978, 0x24, 1);
        if (flag > 0) {
            delete self;
        }
    }
    return self;
}
}
