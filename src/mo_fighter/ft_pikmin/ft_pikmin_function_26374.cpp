#pragma force_active on
extern "C" {
extern unsigned char lbl_113_bss_244[];
extern unsigned char lbl_113_bss_238[];

void fn_113_263BC(void* state);
void* fn_113_262D4(void* object, short deleting);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_113_26374() {
    fn_113_263BC(lbl_113_bss_244);
    __register_global_object(
        lbl_113_bss_244,
        reinterpret_cast<void*>(fn_113_262D4),
        lbl_113_bss_238);
}
}

__declspec(section ".ctors") extern void* const fn_113_26374_ctor = (void*)fn_113_26374;
