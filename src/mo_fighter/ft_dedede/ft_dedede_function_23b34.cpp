#pragma force_active on
// fn_117_23B34 stores the address of the module's 0x40-byte callback table
// lbl_117_data_C408 into the 4-byte location pointed to by r3: the original
// words at .text[0x23B34,0x23B40) are 3C80xxxx 3884xxxx 90830000 4E800020
// (lis r4, lbl_117_data_C408@ha ; addi r4, r4, lbl_117_data_C408@l ; stw r4,
// 0x0(r3) ; blr). lbl_117_data_C408 is one of the two 0x40-byte callback
// tables of the module (its sibling is lbl_117_data_8690); the +0x2C and
// +0x3C slots of both tables point at the null-callback cluster E6A4/E6B0 and
// the constant-true getter E698.
extern "C" {
extern unsigned char lbl_117_data_C408[0x40];

void fn_117_23B34(void* dest) {
    *static_cast<void**>(dest) = lbl_117_data_C408;
}
}
