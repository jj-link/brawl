#pragma force_active on
extern "C" {
extern unsigned char lbl_100_data_68F0[0x40];

void fn_100_F6CC(void** module) {
    *module = &lbl_100_data_68F0;
}
}
