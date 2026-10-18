#include <types.h>
#pragma force_active on

extern "C" u8 lbl_2_data_4D38[0x140];

extern "C" s32 fn_2_39F9C(void*, s32 index) {
    return *reinterpret_cast<s32*>(lbl_2_data_4D38 + index * 0x14 + 0x8);
}
