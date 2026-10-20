#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_CDA70(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

struct fn27Obj {
    u8 unk0[0xc];
    u8 arr[0xc0];
};

extern "C" fn27Obj* fn_27_19ECCC(fn27Obj* self, int flag) {
    if (self) {
        __destroy_arr(self->arr, fn_27_CDA70, 0x10, 0xc);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
