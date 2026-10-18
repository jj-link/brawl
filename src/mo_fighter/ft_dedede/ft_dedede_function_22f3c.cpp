#pragma force_active on
// fn_117_22F3C stores the address of the module's 0x40-byte .data block
// (lbl_117_data_C390) into the location referenced by r3. The only
// relocations in the original slice are R_PPC_ADDR16_HA / R_PPC_ADDR16_LO
// against that .data symbol, matching a plain load-and-store of the label.
extern "C" {
extern unsigned char lbl_117_data_C390[0x40];

void fn_117_22F3C(unsigned char** out) {
    *out = lbl_117_data_C390;
}
}
