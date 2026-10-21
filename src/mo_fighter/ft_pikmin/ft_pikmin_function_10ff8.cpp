#pragma force_active on
extern "C" void fn_113_11040(void*);
extern "C" void* fn_113_10FB8(void*, short);
extern "C" void* __register_global_object(void*, void*, void*);
extern "C" unsigned char lbl_113_bss_E4[];
extern "C" unsigned char lbl_113_bss_D8[];

extern "C" void fn_113_10FF8() {
    fn_113_11040(lbl_113_bss_E4);
    __register_global_object(
        lbl_113_bss_E4,
        reinterpret_cast<void*>(fn_113_10FB8),
        lbl_113_bss_D8
    );
}

__declspec(section ".ctors") extern void* const fn_113_10FF8_ctor = (void*)fn_113_10FF8;
