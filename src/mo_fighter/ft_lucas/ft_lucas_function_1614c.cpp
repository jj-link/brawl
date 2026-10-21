#pragma force_active on
extern "C" {
extern unsigned char lbl_114_bss_344;
extern unsigned char lbl_114_bss_338[12];

void fn_114_16194(void* out);
void* fn_114_1610C(void* object, short size);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_114_1614C(void) {
    fn_114_16194(&lbl_114_bss_344);
    __register_global_object(&lbl_114_bss_344, (void*)fn_114_1610C, lbl_114_bss_338);
}
}

__declspec(section ".ctors") extern void* const fn_114_1614C_ctor = (void*)fn_114_1614C;
