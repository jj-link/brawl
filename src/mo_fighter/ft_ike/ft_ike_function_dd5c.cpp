#pragma force_active on
extern "C" {
extern void* lbl_119_bss_254;
extern char lbl_119_bss_248[12];
void fn_119_DDA4(void** p);
void* fn_119_DD1C(void* p, short n);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_119_DD5C(void)
{
    fn_119_DDA4(&lbl_119_bss_254);
    __register_global_object(&lbl_119_bss_254, (void*)fn_119_DD1C, lbl_119_bss_248);
}

__declspec(section ".ctors") extern void* const fn_119_DD5C_ctor = (void*)fn_119_DD5C;
