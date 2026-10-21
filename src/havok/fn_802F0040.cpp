#pragma force_active on
typedef signed char s8;

extern s8 lbl_805A0F20;

extern "C" void fn_802F0040(void) {
    lbl_805A0F20 = 0;
}

__declspec(section ".ctors") extern void* const fn_802F0040_ctor = (void*)fn_802F0040;
