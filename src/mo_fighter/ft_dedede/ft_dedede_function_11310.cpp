#include <types.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_117_data_88A8[0x40];

void fn_117_11310(void* out) {
    *reinterpret_cast<void**>(out) = lbl_117_data_88A8;
}
}
