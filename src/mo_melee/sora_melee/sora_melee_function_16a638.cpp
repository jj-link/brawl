#pragma force_active on
extern "C" {
void* __register_global_object(void* object, void* destructor, void* chain);
void* fn_27_16A5F8(void* ptr, int count);
extern char lbl_27_data_2EEEC[];
extern void* lbl_27_bss_4994;
extern char lbl_27_bss_4988[];

void fn_27_16A638() {
    lbl_27_bss_4994 = lbl_27_data_2EEEC;
    __register_global_object(&lbl_27_bss_4994, (void*)fn_27_16A5F8, lbl_27_bss_4988);
}
}

__declspec(section ".ctors") extern void* const fn_27_16A638_ctor = (void*)fn_27_16A638;
