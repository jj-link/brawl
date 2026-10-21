#pragma force_active on
extern "C" {
extern unsigned char lbl_113_bss_27C;
extern unsigned char lbl_113_bss_270;
void fn_113_270BC(void*);
void fn_113_27034(void*, short);
void* __register_global_object(void*, void*, void*);

void fn_113_27074() {
    fn_113_270BC(&lbl_113_bss_27C);
    __register_global_object(&lbl_113_bss_27C, (void*)fn_113_27034, &lbl_113_bss_270);
}
}

__declspec(section ".ctors") extern void* const fn_113_27074_ctor = (void*)fn_113_27074;
