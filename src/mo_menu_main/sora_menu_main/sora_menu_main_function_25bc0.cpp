#include <types.h>
#pragma force_active on

struct Fn2Entry {
    u8 storage[0x10];
    s32 value;
};

extern "C" const Fn2Entry lbl_2_rodata_B40[];

extern "C" s32 fn_2_25BC0(s32 index) {
    return lbl_2_rodata_B40[index].value;
}
