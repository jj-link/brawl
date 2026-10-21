#pragma force_active on
extern "C" {
extern float lbl_805A0298;
extern float lbl_805A029C;
extern float lbl_805A2148;
extern float lbl_805A214C;

void fn_800A9DB8(void) {
    lbl_805A0298 = lbl_805A2148;
    lbl_805A029C = lbl_805A214C;
}
}

__declspec(section ".ctors") extern void* const fn_800A9DB8_ctor = (void*)fn_800A9DB8;
