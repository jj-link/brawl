#pragma force_active on
extern char lbl_805A0EE4;

void fn_80280C14(void) {
    lbl_805A0EE4 = 0;
}

__declspec(section ".ctors") extern void* const fn_80280C14_ctor = (void*)fn_80280C14;
