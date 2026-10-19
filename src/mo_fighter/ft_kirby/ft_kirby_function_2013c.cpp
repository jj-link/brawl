#pragma force_active on
extern "C" {
void fn_27_356820(void*);
void fn_27_356830(void*, int);
void* __register_global_object(void* object, void* destructor, void* chain);

extern unsigned char lbl_96_bss_1020;
extern int lbl_96_bss_1024;
extern unsigned char lbl_96_bss_EBC[12];

void* fn_96_2013C() {
    if ((signed char)lbl_96_bss_1020 == 0) {
        fn_27_356820(&lbl_96_bss_1024);
        __register_global_object(&lbl_96_bss_1024, (void*)fn_27_356830, lbl_96_bss_EBC);
        lbl_96_bss_1020 = 1;
    }
    return &lbl_96_bss_1024;
}
}
