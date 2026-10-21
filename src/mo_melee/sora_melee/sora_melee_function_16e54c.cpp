#pragma force_active on
extern "C" void fn_27_16AD18(void* self);
extern "C" void fn_27_16E50C(void* ptr, int shouldDelete);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);
extern "C" char lbl_27_bss_4A4C[];
extern "C" char lbl_27_bss_4A40[];
extern "C" char lbl_27_data_2F3D8[];

extern "C" void fn_27_16E54C() {
    fn_27_16AD18(lbl_27_bss_4A4C);
    *(void**)lbl_27_bss_4A4C = lbl_27_data_2F3D8;
    __register_global_object(lbl_27_bss_4A4C, (void*)fn_27_16E50C, lbl_27_bss_4A40);
}

__declspec(section ".ctors") extern void* const fn_27_16E54C_ctor = (void*)fn_27_16E54C;
