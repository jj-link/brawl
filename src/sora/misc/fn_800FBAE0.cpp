#pragma force_active on
extern "C" {
extern int lbl_8049E550[];
extern char lbl_805A02F8;

void fn_800FBAE0(void) {
    if (lbl_805A02F8)
        return;
    lbl_8049E550[1] = 0;
    lbl_8049E550[0] = 0;
    lbl_8049E550[2] = 0;
    lbl_805A02F8 = 1;
}
}

__declspec(section ".ctors") extern void* const fn_800FBAE0_ctor = (void*)fn_800FBAE0;
