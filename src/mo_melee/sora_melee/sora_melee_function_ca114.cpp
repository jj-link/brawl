#include <types.h>

#pragma force_active on

extern "C" {
void fn_27_A6948(void*);
void fn_27_A6978(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern char lbl_27_data_1FB90[];

char* fn_27_CA114(char* self) {
    *(void**)self = lbl_27_data_1FB90;
    *(void**)(self + 4) = lbl_27_data_1FB90 + 0x48;
    *(u32*)(self + 8) &= 0x0000FFFF;
    __construct_array(self + 0xc, (void (*)(void*))fn_27_A6948, (void (*)(void*))fn_27_A6978, 0x24, 0xa);
    return self;
}
}
