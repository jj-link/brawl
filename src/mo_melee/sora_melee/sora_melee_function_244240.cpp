#include <types.h>
#pragma force_active on

extern "C" void fn_27_242764(void* self);
extern "C" u8 lbl_27_data_4E350[];

extern "C" void* fn_27_244240(void* p) {
    fn_27_242764(p);
    *(void**)((u8*)p + 0x3C) = lbl_27_data_4E350;
    return p;
}
