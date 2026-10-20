#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_3C798[];
void fn_27_AB128(void*);
void fn_27_AB18C(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);

void* fn_27_19E930(char* self) {
    *(char**)(self + 0x0) = lbl_27_data_3C798;
    *(char**)(self + 0x4) = lbl_27_data_3C798 + 0x48;
    *(u32*)(self + 0x8) = *(u32*)(self + 0x8) & 0x1FFF;
    __construct_array(self + 0xc, fn_27_AB128, fn_27_AB18C, 0x14, 0x14);
    return self;
}
}
