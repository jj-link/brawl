#pragma force_active on
#include <types.h>

extern "C" {
extern unsigned char lbl_27_data_370D0[];
void fn_27_D2A0C(void*);
void* fn_27_AB510(void*, s32);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);

void* fn_27_1A19A8(void* self) {
    unsigned int* p = (unsigned int*)self;
    p[0] = (unsigned int)lbl_27_data_370D0;
    p[1] = (unsigned int)(lbl_27_data_370D0 + 0x48);
    p[2] &= 0x1FFF;
    __construct_array((char*)self + 0x0C, fn_27_D2A0C,
                      (void (*)(void*))fn_27_AB510, 0x10, 0x12);
    return self;
}
}
