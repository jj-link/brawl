#pragma force_active on
extern "C" {
extern int lbl_92_bss_234;
extern char lbl_92_bss_228[12];
void fn_92_F6F0(void* object);
void* fn_92_F60C(void* ptr, short size);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_92_F6A8() {
    fn_92_F6F0(&lbl_92_bss_234);
    __register_global_object(&lbl_92_bss_234, (void*)fn_92_F60C, lbl_92_bss_228);
}
}

__declspec(section ".ctors") extern void* const fn_92_F6A8_ctor = (void*)fn_92_F6A8;
