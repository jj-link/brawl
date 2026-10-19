#pragma force_active on
extern "C" {
void fn_800B753C(void*, float);
void setUpdateRate__16gfModelAnimationFf(void*, float);
}
extern const float lbl_31_rodata_34;
extern const float lbl_31_rodata_40;

extern "C" void fn_31_2BDC(char* self) {
    if (*(unsigned char*)(self + 0x5a) == 0) {
        char* e = *(char**)(self + 0x3f8);
        fn_800B753C(e, lbl_31_rodata_34);
        setUpdateRate__16gfModelAnimationFf(*(void**)(e + 0x14), lbl_31_rodata_40);
    }
}
