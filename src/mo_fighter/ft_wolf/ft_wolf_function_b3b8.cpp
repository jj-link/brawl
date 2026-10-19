#include <types.h>
#pragma force_active on

struct X {
    u32 a;
    u32 b;
    u32 c;
    s32* arr;
};

extern "C" s32 fn_125_B3B8(const X* this_ptr, u32 index) {
    return this_ptr->arr[index];
}
