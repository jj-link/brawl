#pragma force_active on
extern "C" void fn_95_13AE0(void* ptr, short size);
extern "C" void fn_95_13B68(void* ptr);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

extern char lbl_95_bss_43C[];
extern char lbl_95_bss_430[];

extern "C" void fn_95_13B20() {
    fn_95_13B68(lbl_95_bss_43C);
    __register_global_object(lbl_95_bss_43C, (void*)fn_95_13AE0, lbl_95_bss_430);
}

__declspec(section ".ctors") extern void* const fn_95_13B20_ctor = (void*)fn_95_13B20;
