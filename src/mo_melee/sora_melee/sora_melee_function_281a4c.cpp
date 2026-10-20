#pragma force_active on
extern "C" {
extern char lbl_27_data_2BEE8[];
extern const float lbl_27_rodata_461C;
}

extern "C" void fn_27_281A4C(unsigned char* p) {
    *(char**)(p + 0x0) = lbl_27_data_2BEE8;
    p[0x4] = 0;
    *(float*)(p + 0x8) = lbl_27_rodata_461C;
    *(float*)(p + 0xC) = lbl_27_rodata_461C;
}
