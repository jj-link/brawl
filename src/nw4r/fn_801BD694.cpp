#pragma force_active on
extern "C" {
    extern int lbl_805A0578;

    void fn_801BD694(void) {
        lbl_805A0578 = 0;
    }
}

__declspec(section ".ctors") extern void* const fn_801BD694_ctor = (void*)fn_801BD694;
