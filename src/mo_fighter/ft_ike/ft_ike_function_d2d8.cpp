#pragma force_active on
extern "C" {
extern char lbl_119_bss_244[4];
extern char lbl_119_bss_238[12];
void fn_119_D320(void *object);
void *fn_119_D290(void *p, short flag);
void *__register_global_object(void *object, void *destructor, void *chain);
}

extern "C" void fn_119_D2D8() {
    fn_119_D320(lbl_119_bss_244);
    __register_global_object(lbl_119_bss_244, (void *)fn_119_D290, lbl_119_bss_238);
}

__declspec(section ".ctors") extern void* const fn_119_D2D8_ctor = (void*)fn_119_D2D8;
