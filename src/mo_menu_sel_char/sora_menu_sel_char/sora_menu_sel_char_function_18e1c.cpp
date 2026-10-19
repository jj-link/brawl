#include <stddef.h>
#pragma force_active on

extern "C" {
void fn_16_5A8(void* self, const char* name, int a, int c);
}

extern "C" void fn_10_18E1C(void* self) {
    int value = *(int*)((char*)self + 0x1DC);
    *(int*)((char*)self + 0x400) = value;
    fn_16_5A8((char*)self + 0x370, (const char*)0, 0, 5);
}
