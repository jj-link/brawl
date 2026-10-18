#pragma force_active on
extern "C" {
extern unsigned char lbl_99_data_22E0[];
}

extern "C" void fn_99_60A0(void* object, unsigned char value) {
    *(void**)object = lbl_99_data_22E0;
    ((unsigned char*)object)[4] = value;
}
