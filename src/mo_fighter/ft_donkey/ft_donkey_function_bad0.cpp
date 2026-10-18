#pragma force_active on
extern "C" const float lbl_92_rodata_8;

extern "C" void fn_92_BAD0(float* p) {
    p[0] = lbl_92_rodata_8;
    p[1] = lbl_92_rodata_8;
    p[2] = lbl_92_rodata_8;
}
