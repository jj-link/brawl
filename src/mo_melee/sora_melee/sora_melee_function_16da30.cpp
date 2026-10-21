#pragma force_active on
extern "C" {
extern char lbl_27_data_2F238[];
extern char lbl_27_bss_4A1C[];
extern char lbl_27_bss_4A10[];
void fn_27_16AD18(void* self);
void* fn_27_16D9F0(void* ptr, int count);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_27_16DA30() {
    fn_27_16AD18(lbl_27_bss_4A1C);
    *(void**)lbl_27_bss_4A1C = lbl_27_data_2F238;
    __register_global_object(lbl_27_bss_4A1C, (void*)fn_27_16D9F0, lbl_27_bss_4A10);
}
}

__declspec(section ".ctors") extern void* const fn_27_16DA30_ctor = (void*)fn_27_16DA30;
