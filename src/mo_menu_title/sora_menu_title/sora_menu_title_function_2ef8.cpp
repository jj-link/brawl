#pragma force_active on
extern "C" unsigned char lbl_24_data_8D0[];

extern "C" void fn_24_2EF8(unsigned char* object) {
    *(void**)(object + 0x200) = lbl_24_data_8D0;
}
