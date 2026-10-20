#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_27_A6978(void*, int);
extern "C" void __dl__FPv(void*);

struct fn_27_CAB14_Obj {
    u8 pad[0xC];
    u8 arr[0x24 * 0x11];
};

extern "C" fn_27_CAB14_Obj* fn_27_CAB14(fn_27_CAB14_Obj* self, int flag) {
    if (self != nullptr) {
        __destroy_arr(self->arr, fn_27_A6978, 0x24, 0x11);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
