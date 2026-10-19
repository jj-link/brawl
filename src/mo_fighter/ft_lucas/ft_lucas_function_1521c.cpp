#include <types.h>
#pragma force_active on

extern "C" void fn_114_8AE8(void* self, u8 value);
extern "C" char lbl_114_data_8FF8[];

extern "C" void* fn_114_1521C(void* self, void* arg) {
    fn_114_8AE8(self, 0);
    *(void**)self = (void*)lbl_114_data_8FF8;
    *(void**)((char*)self + 0x8) = arg;
    *(int*)((char*)self + 0xc) = -1;
    return self;
}
