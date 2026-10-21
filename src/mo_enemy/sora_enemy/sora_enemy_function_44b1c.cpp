#pragma force_active on
struct V3 {
    float x;
    float y;
    float z;
};

extern "C" V3* fn_41_5AC4(V3*, float, float, float);

extern V3 lbl_41_bss_470;
extern V3 lbl_41_bss_47C;
extern float lbl_41_rodata_F8C;
extern float lbl_41_rodata_F90;

extern "C" void fn_41_44B1C() {
    fn_41_5AC4(&lbl_41_bss_470, lbl_41_rodata_F8C, lbl_41_rodata_F8C, lbl_41_rodata_F90);
    fn_41_5AC4(&lbl_41_bss_47C, lbl_41_rodata_F90, lbl_41_rodata_F8C, lbl_41_rodata_F8C);
}

__declspec(section ".ctors") extern void* const fn_41_44B1C_ctor = (void*)fn_41_44B1C;
