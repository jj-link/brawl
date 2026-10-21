#pragma force_active on
extern "C" {

extern int lbl_805A0578;
extern int* lbl_805A0610;

void fn_801CF990(void) {
    lbl_805A0610 = &lbl_805A0578;
}

}

__declspec(section ".ctors") extern void* const fn_801CF990_ctor = (void*)fn_801CF990;
