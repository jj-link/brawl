#pragma force_active on
extern "C" void fn_41_C614(unsigned int*, unsigned int, unsigned int);

extern "C" unsigned char lbl_41_bss_14[];
extern "C" unsigned char lbl_41_bss_1C[];

extern "C" void fn_41_C5D0() {
    fn_41_C614(reinterpret_cast<unsigned int*>(lbl_41_bss_14), 0xFF, 0);
    fn_41_C614(reinterpret_cast<unsigned int*>(lbl_41_bss_1C), 0xFF, 1);
}

__declspec(section ".ctors") extern void* const fn_41_C5D0_ctor = (void*)fn_41_C5D0;
