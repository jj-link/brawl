#pragma force_active on
extern "C" void fn_41_C614(unsigned int* p1, unsigned int p2, unsigned int p3);

extern "C" unsigned int lbl_41_bss_360[2];
extern "C" unsigned int lbl_41_bss_368[2];

extern "C" void fn_41_39E20() {
    fn_41_C614(lbl_41_bss_360, 0xFF, 0);
    fn_41_C614(lbl_41_bss_368, 0xFF, 1);
}

__declspec(section ".ctors") extern void* const fn_41_39E20_ctor = (void*)fn_41_39E20;
