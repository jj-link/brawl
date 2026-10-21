#pragma force_active on
extern "C" {
void* fn_115_DD6C(void* object);
void* fn_115_DCD8(void* ptr, short size);
void* __register_global_object(void* object, void* destructor, void* chain);
unsigned char lbl_115_bss_248[];
unsigned char lbl_115_bss_254[];
}

extern "C" void fn_115_DD24() {
    fn_115_DD6C(lbl_115_bss_254);
    __register_global_object(lbl_115_bss_254, fn_115_DCD8, lbl_115_bss_248);
}

__declspec(section ".ctors") extern void* const fn_115_DD24_ctor = (void*)fn_115_DD24;
