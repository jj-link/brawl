#pragma force_active on
extern "C" {
extern int lbl_105_bss_2DC;
extern int lbl_105_bss_2D0[3];
void fn_105_15040(void* arg0);
void* fn_105_14FB8(void* ptr, short size);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_105_14FF8() {
    fn_105_15040(&lbl_105_bss_2DC);
    __register_global_object(&lbl_105_bss_2DC, (void*)fn_105_14FB8, lbl_105_bss_2D0);
}

__declspec(section ".ctors") extern void* const fn_105_14FF8_ctor = (void*)fn_105_14FF8;
