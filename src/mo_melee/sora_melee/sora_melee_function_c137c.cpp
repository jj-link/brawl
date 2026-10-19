#include <types.h>
#pragma force_active on

extern "C" void fn_27_C13DC(void* self, void* vtable, void* data);

extern "C" void fn_27_C137C(void* self, void* data) {
    __declspec(align(1)) float local[4];
    fn_27_C13DC(local, (char*)self + 4, data);
    *(float*)((char*)self + 0x14) = local[0];
    *(float*)((char*)self + 0x18) = local[1];
    *(float*)((char*)self + 0x1C) = local[2];
    *(float*)((char*)self + 0x20) = local[3];
    *(char*)((char*)self + 0x35) = 1;
}
