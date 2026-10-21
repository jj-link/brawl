#pragma force_active on
extern int lbl_805A0500;
extern int* lbl_805A0518;

extern "C" {
void fn_801856BC(void) {
    lbl_805A0518 = &lbl_805A0500;
}
}

__declspec(section ".ctors") extern void* const fn_801856BC_ctor = (void*)fn_801856BC;
