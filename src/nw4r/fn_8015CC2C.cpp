#pragma force_active on
extern "C" {

extern int lbl_805A0478;

void fn_8015CC2C(void) {
    lbl_805A0478 = 0;
}

}

__declspec(section ".ctors") extern void* const fn_8015CC2C_ctor = (void*)fn_8015CC2C;
