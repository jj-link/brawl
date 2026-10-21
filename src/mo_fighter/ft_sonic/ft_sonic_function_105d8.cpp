#pragma force_active on
extern "C" void fn_123_10620(void*);
extern "C" void* fn_123_10598(void*, short);
extern "C" void* __register_global_object(void*, void*, void*);
extern "C" unsigned char lbl_123_bss_314[];
extern "C" unsigned char lbl_123_bss_308[];

extern "C" void fn_123_105D8() {
    fn_123_10620(lbl_123_bss_314);
    __register_global_object(lbl_123_bss_314, (void*)fn_123_10598, lbl_123_bss_308);
}

__declspec(section ".ctors") extern void* const fn_123_105D8_ctor = (void*)fn_123_105D8;
