// fn_117_11BAC stores the address of the 0x40-byte .data block
// lbl_117_data_8938 into the object pointed to by r3.
#include <types.h>
#pragma force_active on

struct DededeDataRef {
    void* data;
};

extern "C" {
extern u8 lbl_117_data_8938[0x40];

void fn_117_11BAC(DededeDataRef* ref) {
    ref->data = lbl_117_data_8938;
}
}
