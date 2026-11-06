#pragma force_active on
extern "C" {
extern char lbl_27_data_32900[];
extern char lbl_27_bss_5010[];
extern void* lbl_27_bss_501C;
void fn_27_1926BC(void*, int);
void __register_global_object(void*, void*, void*);
void fn_27_1926FC() {
    lbl_27_bss_501C = 0;
    lbl_27_bss_501C = lbl_27_data_32900;
    __register_global_object(&lbl_27_bss_501C, fn_27_1926BC, lbl_27_bss_5010);
}
}

__declspec(section ".ctors") extern void* const fn_27_1926FC_ctor = (void*)fn_27_1926FC;
