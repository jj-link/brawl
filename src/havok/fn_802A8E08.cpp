#pragma force_active on
extern "C" {
    extern unsigned char lbl_805A0F10;
    extern unsigned char lbl_805A0F14;

    void fn_802A8E08(void) {
        lbl_805A0F10 = 0;
        lbl_805A0F14 = 1;
    }
}

__declspec(section ".ctors") extern void* const fn_802A8E08_ctor = (void*)fn_802A8E08;
