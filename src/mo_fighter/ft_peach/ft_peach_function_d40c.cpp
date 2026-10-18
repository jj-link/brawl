#include <ft/ft_entry.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_103_D40C(u32* info) {
    extern u8 lbl_103_data_62C0[];
    info[0] = reinterpret_cast<u32>(&lbl_103_data_62C0);
}
}
