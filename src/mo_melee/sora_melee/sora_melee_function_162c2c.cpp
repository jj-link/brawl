#pragma force_active on
extern const float lbl_27_rodata_1FC0;

extern "C" void fn_27_89D08(int, void*, int, void*, void*);

extern "C" void fn_27_162C2C(int, void* unused, void* vec2, void* accesser) {
    float zero[3];
    zero[0] = lbl_27_rodata_1FC0;
    zero[1] = lbl_27_rodata_1FC0;
    zero[2] = lbl_27_rodata_1FC0;
    fn_27_89D08(2, accesser, 5, vec2, zero);
}
