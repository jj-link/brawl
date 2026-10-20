#include <types.h>
#pragma force_active on

extern "C" {
extern void fn_27_C93EC(void);
extern void fn_27_C940C(void);
extern void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern u8 lbl_27_data_1A248[0x90];

struct FooD2 {
    void* f0;
    void* f1;
    u32   f2;
    u32   arr[44];
};

void* fn_27_D2BAC(FooD2* o) {
    o->f0 = lbl_27_data_1A248;
    o->f1 = &lbl_27_data_1A248[0x48];
    o->f2 &= 0x7FFFF;
    __construct_array(o->arr, (void (*)(void*))fn_27_C93EC, (void (*)(void*))fn_27_C940C, 16, 7);
    return o;
}
}
