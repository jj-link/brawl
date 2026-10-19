#pragma force_active on
extern "C" {

void fn_27_34E3B8(void*);
void* fn_27_34E3C8(void*, int);
void* __register_global_object(void*, void*, void*);

extern char lbl_96_bss_1010;
extern int lbl_96_bss_1014;
extern int lbl_96_bss_EA4[3];

void* fn_96_2005C() {
    if (!lbl_96_bss_1010) {
        fn_27_34E3B8(&lbl_96_bss_1014);
        __register_global_object(&lbl_96_bss_1014, fn_27_34E3C8, lbl_96_bss_EA4);
        lbl_96_bss_1010 = 1;
    }
    return &lbl_96_bss_1014;
}

}
