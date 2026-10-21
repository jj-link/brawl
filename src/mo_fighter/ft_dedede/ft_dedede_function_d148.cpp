#pragma force_active on
extern "C" const float lbl_117_rodata_C;
extern "C" const float lbl_117_rodata_10;
extern "C" void* fn_117_D134(void* dst, const void* src);

extern "C" void fn_117_D148(unsigned char* self) {
    float a[2];
    float b[2];
    a[0] = lbl_117_rodata_C;
    a[1] = lbl_117_rodata_C;

    void* r = fn_117_D134(self + 0x20, a);
    r = fn_117_D134(self + 0x10, r);
    r = fn_117_D134(self + 0x08, r);

    b[0] = lbl_117_rodata_10;
    b[1] = lbl_117_rodata_10;
    r = fn_117_D134(self + 0x28, b);
    fn_117_D134(self + 0x18, r);

    self[0x31] = 0;
    self[0x30] = 0;
    self[0x32] = 1;
}
