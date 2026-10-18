#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_117_data_87A0[0x40];

void fn_117_1013C(void* out) {
    *(void**)out = lbl_117_data_87A0;
}
}
