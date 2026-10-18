#include <types.h>
#pragma force_active on

extern "C" const u8 lbl_111_data_5D30[];

extern "C" void fn_111_C9A8(void* object) {
    *reinterpret_cast<const u8**>(object) = lbl_111_data_5D30;
}
