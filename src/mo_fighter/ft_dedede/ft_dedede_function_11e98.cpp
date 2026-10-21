#pragma force_active on
extern "C" {
extern unsigned char lbl_117_bss_2EC[];
extern unsigned char lbl_117_bss_2E0[];
void fn_117_11EE0(void*);
void* fn_117_11E38(void*, short);
void __register_global_object(void*, void*, void*);

extern "C" void fn_117_11E98(void) {
    fn_117_11EE0(lbl_117_bss_2EC);
    __register_global_object(lbl_117_bss_2EC, reinterpret_cast<void*>(fn_117_11E38), lbl_117_bss_2E0);
}
}

__declspec(section ".ctors") extern void* const fn_117_11E98_ctor = (void*)fn_117_11E98;
