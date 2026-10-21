#pragma force_active on
extern "C" void fn_41_C614(unsigned int* p1, unsigned int p2, unsigned int p3);

extern "C" unsigned int lbl_41_bss_308[2];
extern "C" unsigned int lbl_41_bss_310[2];

extern "C" void fn_41_38C0C() {
    fn_41_C614(&lbl_41_bss_308[0], 0xff, 0);
    fn_41_C614(&lbl_41_bss_310[0], 0xff, 1);
}

__declspec(section ".ctors") extern void* const fn_41_38C0C_ctor = (void*)fn_41_38C0C;
