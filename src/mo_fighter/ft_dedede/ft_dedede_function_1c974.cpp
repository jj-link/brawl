#include <types.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_117_data_A0E0[0x40];

// Stores the address of the 0x40-byte data block lbl_117_data_A0E0 into the
// object pointed to by the argument; no value is returned.
void fn_117_1C974(void** object) {
    *object = lbl_117_data_A0E0;
}
}
