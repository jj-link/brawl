#include <stddef.h>
#pragma force_active on

extern "C" float fn_63_10A34(const void* self, unsigned int index) {
    float* arr = *(float**)((char*)self + 0x51c);
    return arr[index];
}
