#pragma force_active on
extern "C" {
extern int lbl_34_bss_8[2];
extern int lbl_34_bss_10[2];

void fn_34_1684() {
    lbl_34_bss_8[0] = 0xFF;
    lbl_34_bss_8[1] = 0;
    lbl_34_bss_10[0] = 0xFF;
    lbl_34_bss_10[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_34_1684_ctor = (void*)fn_34_1684;
