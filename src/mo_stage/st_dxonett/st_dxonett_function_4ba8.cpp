#include <types.h>
#pragma force_active on

extern "C" float fn_78_4BA8(const void* container, u32 index) {
    const float* floats = *(const float* const*)((const char*)container + 0x520);
    return floats[index];
}
