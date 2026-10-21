#pragma force_active on
extern "C" {
void fn_100_DF44(void* object);
void* fn_100_DEBC(void* ptr, short size);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern char lbl_100_bss_1E4[4];
extern char lbl_100_bss_1D8[12];

extern "C" {
void fn_100_DEFC() {
    fn_100_DF44(lbl_100_bss_1E4);
    __register_global_object(lbl_100_bss_1E4, (void*)fn_100_DEBC, lbl_100_bss_1D8);
}
}

__declspec(section ".ctors") extern void* const fn_100_DEFC_ctor = (void*)fn_100_DEFC;
