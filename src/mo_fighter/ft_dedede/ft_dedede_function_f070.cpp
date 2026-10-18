#pragma force_active on
// fn_117_F070 stores the address of the 0x40-byte .data block
// lbl_117_data_8608 into the pointer slot pointed to by r3. The original
// words at .text[0xF070,0xF080) are 3C800000 38840000 90830000 4E800020,
// with R_PPC_ADDR16_HA / R_PPC_ADDR16_LO relocations against
// .data + 0x8608 at the lis/addi.
extern "C" {
extern unsigned char lbl_117_data_8608[];

void fn_117_F070(void* dst) {
    *static_cast<void**>(dst) = lbl_117_data_8608;
}
}
