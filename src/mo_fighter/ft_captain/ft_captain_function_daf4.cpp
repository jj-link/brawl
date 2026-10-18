#pragma force_active on
extern "C" {
extern const unsigned char lbl_100_data_6338[];
}

extern "C" void fn_100_DAF4(void *p) {
    *(const void **)p = &lbl_100_data_6338;
}
