#pragma force_active on
extern "C" {
void* fn_115_F328(void* object);
void* fn_115_F2A0(void* ptr, short count);
void* __register_global_object(void* object, void* destructor, void* chain);
extern char lbl_115_bss_2B4[];
extern char lbl_115_bss_2A8[];
}

extern "C" void fn_115_F2E0() {
    fn_115_F328(lbl_115_bss_2B4);
    __register_global_object(lbl_115_bss_2B4, (void*)fn_115_F2A0, lbl_115_bss_2A8);
}

__declspec(section ".ctors") extern void* const fn_115_F2E0_ctor = (void*)fn_115_F2E0;
