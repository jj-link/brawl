#pragma force_active on
extern "C" {
void fn_96_2DA94(void* obj);
void* fn_96_2DA0C(void* self, short flags);
extern char lbl_96_bss_12EC[4];
extern char lbl_96_bss_12E0[12];
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_96_2DA4C() {
    fn_96_2DA94(lbl_96_bss_12EC);
    __register_global_object(lbl_96_bss_12EC, (void*)fn_96_2DA0C, lbl_96_bss_12E0);
}

__declspec(section ".ctors") extern void* const fn_96_2DA4C_ctor = (void*)fn_96_2DA4C;
