#pragma force_active on
extern "C" {
void* fn_105_14964(void* object);
void* fn_105_148DC(void* p, short flags);
void* __register_global_object(void* object, void* destructor, void* chain);
extern char lbl_105_bss_2BC[];
extern char lbl_105_bss_2B0[];
}

extern "C" void fn_105_1491C() {
    fn_105_14964(lbl_105_bss_2BC);
    __register_global_object(lbl_105_bss_2BC, (void*)fn_105_148DC, lbl_105_bss_2B0);
}

__declspec(section ".ctors") extern void* const fn_105_1491C_ctor = (void*)fn_105_1491C;
