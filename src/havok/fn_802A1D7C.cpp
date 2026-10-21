#pragma force_active on
extern "C" {
extern unsigned char lbl_805A0F08;

void fn_802A1D7C(void) {
    lbl_805A0F08 = 0;
}
}

__declspec(section ".ctors") extern void* const fn_802A1D7C_ctor = (void*)fn_802A1D7C;
