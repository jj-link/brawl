#pragma force_active on
extern "C" {
extern unsigned int lbl_41_bss_48[];
extern unsigned int lbl_41_bss_50[];
void fn_41_C614(unsigned int*, unsigned int, unsigned int);

void fn_41_13718() {
    fn_41_C614(lbl_41_bss_48, 0xFF, 0);
    fn_41_C614(lbl_41_bss_50, 0xFF, 1);
}
}

__declspec(section ".ctors") extern void* const fn_41_13718_ctor = (void*)fn_41_13718;
