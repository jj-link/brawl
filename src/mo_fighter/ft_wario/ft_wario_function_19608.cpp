#pragma force_active on
extern "C" {
extern unsigned char lbl_110_bss_3B4[];
extern unsigned char lbl_110_bss_3A8[];
void fn_110_19650(void* p);
void* fn_110_195C8(void* p, short flag);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_110_19608() {
    fn_110_19650(lbl_110_bss_3B4);
    __register_global_object(lbl_110_bss_3B4, (void*)fn_110_195C8, lbl_110_bss_3A8);
}

__declspec(section ".ctors") extern void* const fn_110_19608_ctor = (void*)fn_110_19608;
