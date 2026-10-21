#pragma force_active on
extern "C" {
extern unsigned char lbl_107_bss_1FC[4];
extern unsigned char lbl_107_bss_1F0[12];
void fn_107_13554(unsigned char *arg0);
void* fn_107_134CC(void* slot, short destroy);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_107_1350C() {
    fn_107_13554(lbl_107_bss_1FC);
    __register_global_object(lbl_107_bss_1FC, (void*)fn_107_134CC, lbl_107_bss_1F0);
}

__declspec(section ".ctors") extern void* const fn_107_1350C_ctor = (void*)fn_107_1350C;
