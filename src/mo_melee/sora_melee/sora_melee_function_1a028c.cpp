#pragma force_active on
#include <types.h>
extern "C" {
extern u8 lbl_27_data_377D0[];
void fn_27_1A02F8(void*);
void fn_27_1A032C(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);

void* fn_27_1A028C(void* self) {
    char* p = (char*)self;
    *(void**)(p + 0x0) = lbl_27_data_377D0;
    *(void**)(p + 0x4) = lbl_27_data_377D0 + 0x48;
    *(unsigned int*)(p + 0x8) &= 0x000003FF;
    __construct_array(p + 0xc, (void (*)(void*))fn_27_1A02F8, (void (*)(void*))fn_27_1A032C, 0x10, 0x24);
    return self;
}

}
