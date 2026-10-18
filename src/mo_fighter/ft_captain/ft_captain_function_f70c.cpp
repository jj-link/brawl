#pragma force_active on
extern "C" {
extern unsigned char lbl_100_data_6704[0x40];

void fn_100_F70C(unsigned char** arg0) {
    *arg0 = lbl_100_data_6704;
}
}
