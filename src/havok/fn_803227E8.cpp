#pragma force_active on
extern "C" {
extern signed char lbl_805A0F28;

void fn_803227E8(void) {
    lbl_805A0F28 = 0;
}
}

__declspec(section ".ctors") extern void* const fn_803227E8_ctor = (void*)fn_803227E8;
