#include <types.h>
#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_CDA70(void*, int);

struct fn_27_19F65C_obj {
    u8 pad[0xc];
    u8 arr[6][0x10];
};

fn_27_19F65C_obj* fn_27_19F65C(fn_27_19F65C_obj* obj, int flag) {
    if (obj) {
        __destroy_arr(obj->arr, fn_27_CDA70, 0x10, 6);
        if (flag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
}
