#pragma force_active on
extern "C" {
extern char lbl_105_bss_2AC[4];
extern char lbl_105_bss_2A0[12];
void* fn_105_14468(void* object);
void fn_105_143E0(void* ptr, short size);
void* __register_global_object(void* object, void* destructor, void* chain);
void fn_105_14420(void);
}

extern "C" void fn_105_14420(void) {
    fn_105_14468(lbl_105_bss_2AC);
    __register_global_object(lbl_105_bss_2AC, (void*)fn_105_143E0, lbl_105_bss_2A0);
}

__declspec(section ".ctors") extern void* const fn_105_14420_ctor = (void*)fn_105_14420;
