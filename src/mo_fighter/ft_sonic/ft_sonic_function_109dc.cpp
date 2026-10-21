#pragma force_active on
extern "C" void fn_123_10A24(void*);
extern "C" void* fn_123_1099C(void*, short);
extern "C" void* __register_global_object(void*, void*, void*);
extern "C" char lbl_123_bss_334[];
extern "C" char lbl_123_bss_328[];

extern "C" void fn_123_109DC() {
    fn_123_10A24(lbl_123_bss_334);
    __register_global_object(lbl_123_bss_334, (void*)fn_123_1099C, lbl_123_bss_328);
}

__declspec(section ".ctors") extern void* const fn_123_109DC_ctor = (void*)fn_123_109DC;
