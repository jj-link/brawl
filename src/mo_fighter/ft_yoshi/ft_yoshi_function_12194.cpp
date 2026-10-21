#pragma force_active on
extern "C" {
extern unsigned char lbl_95_bss_3EC[];
extern unsigned char lbl_95_bss_3E0[];
void fn_95_121DC(void*);
void fn_95_12154(void*, short);
void __register_global_object(void*, void*, void*);

void fn_95_12194(void) {
    fn_95_121DC(lbl_95_bss_3EC);
    __register_global_object(lbl_95_bss_3EC, (void*)fn_95_12154, lbl_95_bss_3E0);
}
}

__declspec(section ".ctors") extern void* const fn_95_12194_ctor = (void*)fn_95_12194;
