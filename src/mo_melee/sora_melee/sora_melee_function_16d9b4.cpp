#pragma force_active on
typedef unsigned int u32;

extern "C" {
    extern const float lbl_27_rodata_21C8;
    void fn_27_16D7A8(void* obj);
    void fn_27_193378(void* obj, float f);
}

extern "C" void fn_27_16D9B4(void* a, void* b) {
    fn_27_16D7A8(a);
    fn_27_193378(b, lbl_27_rodata_21C8);
}
