#pragma force_active on
extern "C" void fn_27_16AD18(void* p);
extern "C" void* fn_27_16E97C(void* ptr, int shouldDelete);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

extern char lbl_27_data_2F468[];
extern char lbl_27_bss_4A50[];
extern void* lbl_27_bss_4A5C;

extern "C" void fn_27_16E9BC() {
    fn_27_16AD18(&lbl_27_bss_4A5C);
    lbl_27_bss_4A5C = lbl_27_data_2F468;
    __register_global_object(&lbl_27_bss_4A5C, (void*)fn_27_16E97C, lbl_27_bss_4A50);
}

__declspec(section ".ctors") extern void* const fn_27_16E9BC_ctor = (void*)fn_27_16E9BC;
