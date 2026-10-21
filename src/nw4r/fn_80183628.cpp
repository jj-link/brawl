#pragma force_active on
extern "C" {
extern int lbl_805A0500;

void fn_80183628(void) {
    lbl_805A0500 = 0;
}
}

__declspec(section ".ctors") extern void* const fn_80183628_ctor = (void*)fn_80183628;
