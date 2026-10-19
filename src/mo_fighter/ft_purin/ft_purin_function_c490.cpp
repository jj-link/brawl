#include <types.h>
#pragma force_active on

extern "C" u8 lbl_124_data_5CD8[];

extern "C" void fn_124_C490(void* obj) {
    *reinterpret_cast<void**>(obj) = lbl_124_data_5CD8;
}
