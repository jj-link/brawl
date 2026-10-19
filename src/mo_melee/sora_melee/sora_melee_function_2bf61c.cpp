#include <types.h>
#pragma force_active on

extern "C" void fn_27_8B574(void* self, s32 flag);
extern "C" u8 lbl_27_data_7A5B8[];

extern "C" void* fn_27_2BF61C(void* self) {
    fn_27_8B574(self, 4);
    *(void**)((u8*)self + 4) = lbl_27_data_7A5B8;
    return self;
}
