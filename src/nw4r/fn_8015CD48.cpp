#pragma force_active on
extern "C" {
    extern int lbl_805A0478[2];
    extern int* lbl_805A0480;

    void fn_8015CD48(void) {
        lbl_805A0480 = lbl_805A0478;
    }
}

__declspec(section ".ctors") extern void* const fn_8015CD48_ctor = (void*)fn_8015CD48;
