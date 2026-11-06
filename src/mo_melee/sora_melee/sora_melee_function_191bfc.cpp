#pragma force_active on

extern "C" {
extern char lbl_27_data_32618[0x40];
extern void* lbl_27_bss_4FBC;
extern char lbl_27_bss_4FB0[0xC];
void fn_27_191BBC(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_191BFC(void) {
    lbl_27_bss_4FBC = 0;
    lbl_27_bss_4FBC = (void*)lbl_27_data_32618;
    __register_global_object(&lbl_27_bss_4FBC, (void*)fn_27_191BBC, lbl_27_bss_4FB0);
}
}

__declspec(section ".ctors") extern void* const fn_27_191BFC_ctor = (void*)fn_27_191BFC;
