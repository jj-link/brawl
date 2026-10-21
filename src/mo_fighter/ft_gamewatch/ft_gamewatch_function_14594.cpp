#pragma force_active on
extern "C" {
void fn_107_145DC(void* object);
void* fn_107_12D10(void* ptr, short flag);
void* __register_global_object(void* object, void* destructor, void* chain);
extern unsigned char lbl_107_bss_23C[4];
extern unsigned char lbl_107_bss_230[12];
}

extern "C" void fn_107_14594() {
    fn_107_145DC(lbl_107_bss_23C);
    __register_global_object(lbl_107_bss_23C, (void*)fn_107_12D10, lbl_107_bss_230);
}

__declspec(section ".ctors") extern void* const fn_107_14594_ctor = (void*)fn_107_14594;
