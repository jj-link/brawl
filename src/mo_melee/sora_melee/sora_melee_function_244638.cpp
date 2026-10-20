#include <types.h>
#pragma force_active on

extern "C" void fn_27_242764(void* self);
extern "C" void* lbl_27_data_4E4C0;

extern "C" void* fn_27_244638(void* self, u8 value) {
    unsigned char* p = (unsigned char*)self;
    fn_27_242764(self);
    p[0x1B6] = value;
    *(void**)(p + 0x3C) = &lbl_27_data_4E4C0;
    *(int*)(p + 0x1B8) = 0;
    p[0x1B5] = 0;
    return self;
}
