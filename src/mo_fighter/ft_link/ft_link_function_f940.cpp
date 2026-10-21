#pragma force_active on
extern "C" {
void fn_93_F988(void **ptr);
void* fn_93_F900(void* p, short flag);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern void* lbl_93_bss_17C;
extern unsigned char lbl_93_bss_170[12];

extern "C" void fn_93_F940(void) {
    fn_93_F988((void**)&lbl_93_bss_17C);
    __register_global_object(&lbl_93_bss_17C, (void*)fn_93_F900, lbl_93_bss_170);
}

__declspec(section ".ctors") extern void* const fn_93_F940_ctor = (void*)fn_93_F940;
