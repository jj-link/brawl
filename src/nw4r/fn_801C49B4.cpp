#pragma force_active on
extern "C" {

extern int lbl_805A0578;
extern int* lbl_805A05A8;

void fn_801C49B4(void) {
    lbl_805A05A8 = &lbl_805A0578;
}

}

__declspec(section ".ctors") extern void* const fn_801C49B4_ctor = (void*)fn_801C49B4;
