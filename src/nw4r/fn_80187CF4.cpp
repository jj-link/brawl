#pragma force_active on
// fn_80187CF4

extern int lbl_805A0500[2];
extern int* lbl_805A0520;

extern "C" void fn_80187CF4() {
    lbl_805A0520 = lbl_805A0500;
}

__declspec(section ".ctors") extern void* const fn_80187CF4_ctor = (void*)fn_80187CF4;
