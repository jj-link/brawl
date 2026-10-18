#pragma force_active on
extern "C" {
extern char lbl_100_data_63B4[0x40];

void fn_100_DAE4(char* object) {
    *(char**)object = &lbl_100_data_63B4[0];
}
}
