#pragma force_active on
extern "C" {
extern unsigned char lbl_95_bss_3FC[];
extern unsigned char lbl_95_bss_3F0[];
void fn_95_12D70(void*);
void fn_95_12CE8(void*, short);
void __register_global_object(void*, void*, void*);

void fn_95_12D28(void) {
    fn_95_12D70(lbl_95_bss_3FC);
    __register_global_object(lbl_95_bss_3FC, (void*)fn_95_12CE8, lbl_95_bss_3F0);
}
}

__declspec(section ".ctors") extern void* const fn_95_12D28_ctor = (void*)fn_95_12D28;
