#pragma force_active on
extern "C" void fn_41_C614(unsigned int*, unsigned int, unsigned int);
extern "C" unsigned int lbl_41_bss_658[2];
extern "C" unsigned int lbl_41_bss_660[2];

extern "C" void fn_41_50FE4() {
    fn_41_C614(lbl_41_bss_658, 0xff, 0);
    fn_41_C614(lbl_41_bss_660, 0xff, 1);
}

__declspec(section ".ctors") extern void* const fn_41_50FE4_ctor = (void*)fn_41_50FE4;
