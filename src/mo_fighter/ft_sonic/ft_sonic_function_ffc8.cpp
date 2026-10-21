#pragma force_active on
extern "C" void fn_123_10010(void*);
extern "C" void* fn_123_FC80(void*, int);
extern "C" void* __register_global_object(void*, void*, void*);
extern "C" unsigned char lbl_123_bss_304[];
extern "C" unsigned char lbl_123_bss_2F8[];

extern "C" void fn_123_FFC8() {
    fn_123_10010(lbl_123_bss_304);
    __register_global_object(lbl_123_bss_304, (void*)fn_123_FC80, lbl_123_bss_2F8);
}

__declspec(section ".ctors") extern void* const fn_123_FFC8_ctor = (void*)fn_123_FFC8;
