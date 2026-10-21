#pragma force_active on
extern "C" {
extern char lbl_805A0F30;

void fn_8032BBDC(void) {
    lbl_805A0F30 = 0;
}
}

__declspec(section ".ctors") extern void* const fn_8032BBDC_ctor = (void*)fn_8032BBDC;
