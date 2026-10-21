#pragma force_active on
extern "C" {
extern unsigned char lbl_105_bss_30C[];
extern unsigned char lbl_105_bss_300[];
void* fn_105_15E88(void** object);
void* fn_105_15E00(void* object, short flag);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_105_15E40() {
    fn_105_15E88((void**)lbl_105_bss_30C);
    __register_global_object(lbl_105_bss_30C, (void*)fn_105_15E00,
                             lbl_105_bss_300);
}

__declspec(section ".ctors") extern void* const fn_105_15E40_ctor = (void*)fn_105_15E40;
