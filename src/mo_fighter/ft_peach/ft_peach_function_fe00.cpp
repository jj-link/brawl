#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_103_data_645C[];

void fn_103_FE00(u32* info) {
    *info = reinterpret_cast<u32>(lbl_103_data_645C);
}
}
