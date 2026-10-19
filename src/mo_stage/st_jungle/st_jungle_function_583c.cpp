#include <types.h>
#pragma force_active on

extern "C" {
extern void fn_51_5ACC(void);
extern void* fn_51_5ADC(void*, int);
extern void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern u8 lbl_51_data_2778[0x90];

void* fn_51_583C(void* self) {
    u32 flags;
    self = self;
    ((void**)self)[10] = lbl_51_data_2778;
    ((void**)self)[11] = lbl_51_data_2778 + 0x48;
    flags = *(u32*)((u8*)self + 0x30);
    *(u32*)((u8*)self + 0x30) = flags & 0x7FFFF;
    __construct_array((u8*)self + 0x34, (void (*)(void*))fn_51_5ACC, (void (*)(void*))fn_51_5ADC, 8, 6);
    return self;
}
}
