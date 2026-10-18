#include <types.h>
#pragma force_active on

extern "C" {
unsigned char lbl_93_data_84E8[];
}

extern "C" void fn_93_10F2C(u32 *module)
{
    module[0] = (u32)lbl_93_data_84E8;
}
