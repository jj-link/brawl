#pragma force_active on
extern "C" {
extern const float lbl_98_rodata_8;
extern const float lbl_98_rodata_C;
void* fn_98_C46C(void*, const void*);

void fn_98_C480(void* object) {
    float first[2] = {lbl_98_rodata_8, lbl_98_rodata_8};
    void* result = fn_98_C46C(static_cast<char*>(object) + 0x20, first);
    result = fn_98_C46C(static_cast<char*>(object) + 0x10, result);
    fn_98_C46C(static_cast<char*>(object) + 0x08, result);

    float second[2] = {lbl_98_rodata_C, lbl_98_rodata_C};
    result = fn_98_C46C(static_cast<char*>(object) + 0x28, second);
    fn_98_C46C(static_cast<char*>(object) + 0x18, result);

    static_cast<unsigned char*>(object)[0x31] = 0;
    static_cast<unsigned char*>(object)[0x30] = 0;
    static_cast<unsigned char*>(object)[0x32] = 1;
}
}
