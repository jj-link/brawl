#pragma force_active on
extern float lbl_40_rodata_54;

extern "C" float fn_40_50BC(char* self) {
    char* p = *(char**)(self + 0x1c0);
    if (p != 0) {
        return *(float*)(p + 0x7c);
    }
    return lbl_40_rodata_54;
}
