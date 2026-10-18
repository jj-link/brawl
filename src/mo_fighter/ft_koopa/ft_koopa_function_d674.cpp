#pragma force_active on
extern "C" {
extern unsigned char lbl_102_data_5F3C[0x40];
}

extern "C" void fn_102_D674(void **object) {
    *object = (void *)&lbl_102_data_5F3C[0];
}
