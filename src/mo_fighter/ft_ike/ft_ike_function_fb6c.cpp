#pragma force_active on
extern "C" {
void* fn_119_FBB4(void* object);
void* fn_119_FB2C(void* p, short flags);
void* __register_global_object(void* object, void* destructor, void* chain);
extern char lbl_119_bss_274[4];
extern char lbl_119_bss_268[12];
}

extern "C" void fn_119_FB6C() {
    fn_119_FBB4(lbl_119_bss_274);
    __register_global_object(lbl_119_bss_274, (void*)fn_119_FB2C, lbl_119_bss_268);
}

__declspec(section ".ctors") extern void* const fn_119_FB6C_ctor = (void*)fn_119_FB6C;
