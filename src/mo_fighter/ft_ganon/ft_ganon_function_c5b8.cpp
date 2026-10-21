#pragma force_active on
extern "C" {
void fn_109_C600(void **ptr);
void* fn_109_C578(void* ptr, short count);
void* __register_global_object(void* object, void* destructor, void* chain);

extern void* lbl_109_bss_154;
extern void* lbl_109_bss_148[3];

void fn_109_C5B8(void) {
    fn_109_C600(&lbl_109_bss_154);
    __register_global_object(&lbl_109_bss_154, (void*)fn_109_C578, &lbl_109_bss_148);
}
}

__declspec(section ".ctors") extern void* const fn_109_C5B8_ctor = (void*)fn_109_C5B8;
