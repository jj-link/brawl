#pragma force_active on
extern "C" void fn_8029F08C(void);

extern "C" {
extern signed char lbl_805A0EF8;
}

extern "C" void fn_8029F08C(void) {
    lbl_805A0EF8 = 0;
}

__declspec(section ".ctors") extern void* const fn_8029F08C_ctor = (void*)fn_8029F08C;
