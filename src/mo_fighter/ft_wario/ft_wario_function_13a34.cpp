#pragma force_active on
extern "C" void fn_110_C79C(void* a0, int a1, int a2);
extern "C" unsigned char lbl_110_bss_240[];
extern "C" unsigned char lbl_110_bss_248[];

extern "C" void fn_110_13A34() {
    fn_110_C79C(lbl_110_bss_240, 0xFF, 0);
    fn_110_C79C(lbl_110_bss_248, 0xFF, 1);
}

__declspec(section ".ctors") extern void* const fn_110_13A34_ctor = (void*)fn_110_13A34;
