#pragma force_active on
extern char lbl_805A0500;
extern char* lbl_805A0528;

extern "C" void fn_80187DA0(void) {
    lbl_805A0528 = &lbl_805A0500;
}

__declspec(section ".ctors") extern void* const fn_80187DA0_ctor = (void*)fn_80187DA0;
