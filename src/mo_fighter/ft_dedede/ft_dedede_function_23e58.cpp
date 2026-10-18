#pragma force_active on
// fn_117_23E58 stores the address of the 0x98-byte .data block
// lbl_117_data_C4E0 into the word pointed to by its argument (r3).
extern "C" {
extern unsigned char lbl_117_data_C4E0[0x98];

void fn_117_23E58(void* out) {
    *static_cast<void**>(out) = lbl_117_data_C4E0;
}
}
