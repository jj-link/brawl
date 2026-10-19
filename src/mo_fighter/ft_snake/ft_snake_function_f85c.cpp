#include <stddef.h>
#pragma force_active on

typedef unsigned int u32;

extern "C" void fn_122_F85C(void *self, u32 value, u32 index) {
    u32 *arr = *(u32 **)((char *)self + 0xc);
    arr[index] = value;
}
