#include <types.h>
#pragma force_active on

extern "C" void OSReport(const char* fmt, ...);
extern "C" char lbl_41_data_3E20[];

extern "C" void fn_41_2CA6C() {
    OSReport(lbl_41_data_3E20);
}
