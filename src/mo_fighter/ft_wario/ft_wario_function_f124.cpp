#pragma force_active on
extern "C" {
void fn_110_F16C(void* p);
void fn_110_F0E4(void* p, short flag);
extern char lbl_110_bss_224[];
extern char lbl_110_bss_218[];
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_110_F124() {
    fn_110_F16C(lbl_110_bss_224);
    __register_global_object(lbl_110_bss_224, (void*)fn_110_F0E4, lbl_110_bss_218);
}

__declspec(section ".ctors") extern void* const fn_110_F124_ctor = (void*)fn_110_F124;
