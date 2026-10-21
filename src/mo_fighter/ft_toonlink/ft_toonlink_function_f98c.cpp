#pragma force_active on
extern "C" {
extern void* lbl_121_bss_17C;
extern unsigned char lbl_121_bss_170[12];
void fn_121_F9D4(void** object);
void* fn_121_F94C(void* ptr, short count);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_121_F98C() {
    fn_121_F9D4(&lbl_121_bss_17C);
    __register_global_object(&lbl_121_bss_17C, (void*)fn_121_F94C, lbl_121_bss_170);
}

__declspec(section ".ctors") extern void* const fn_121_F98C_ctor = (void*)fn_121_F98C;
