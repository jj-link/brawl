#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_6560;
void* fn_27_B62E4(void* self, int a, int arg, float f);
}

extern "C" void* fn_27_3026DC(void* p, int a) {
    fn_27_B62E4(p, a, 0, lbl_27_rodata_6560);
    return p;
}
