#pragma force_active on
extern "C" unsigned char lbl_115_bss_324[];
extern "C" unsigned char lbl_115_bss_318[];

extern "C" void* fn_115_130F0(void* object);
extern "C" void* fn_115_13068(void* ptr, short count);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

extern "C" void fn_115_130A8() {
    fn_115_130F0(lbl_115_bss_324);
    __register_global_object(lbl_115_bss_324, (void*)fn_115_13068, lbl_115_bss_318);
}

__declspec(section ".ctors") extern void* const fn_115_130A8_ctor = (void*)fn_115_130A8;
