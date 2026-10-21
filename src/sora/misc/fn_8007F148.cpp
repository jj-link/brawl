#pragma force_active on
extern "C" {
    extern int lbl_805A0214;
    extern void fn_8007C944(void);

    void fn_8007F148(void) {
        if (lbl_805A0214)
            fn_8007C944();
    }
}
