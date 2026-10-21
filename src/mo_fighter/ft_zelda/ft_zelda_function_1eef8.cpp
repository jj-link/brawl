#pragma force_active on
extern "C" {
extern char lbl_104_bss_504[];
extern char lbl_104_bss_4F8[];
void fn_104_1EF40(void* p);
void* fn_104_1EEB8(void* p, short flags);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_104_1EEF8() {
    fn_104_1EF40(lbl_104_bss_504);
    __register_global_object(lbl_104_bss_504, (void*)fn_104_1EEB8, lbl_104_bss_4F8);
}

__declspec(section ".ctors") extern void* const fn_104_1EEF8_ctor = (void*)fn_104_1EEF8;
