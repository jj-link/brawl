#pragma force_active on
extern "C" {
extern signed char lbl_805A0F00;

void fn_802A0C5C(void) {
    lbl_805A0F00 = 0;
}
}

__declspec(section ".ctors") extern void* const fn_802A0C5C_ctor = (void*)fn_802A0C5C;
