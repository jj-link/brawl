#include <types.h>
#pragma force_active on

extern "C" const u8 lbl_111_data_5ED8[];

extern "C" void fn_111_D6DC(u32* object) {
    *object = reinterpret_cast<u32>(&lbl_111_data_5ED8[0]);
}
