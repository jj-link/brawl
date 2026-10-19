#pragma force_active on
typedef unsigned char u8;

extern "C" {
    void fn_27_3725C8(void*);
    void* fn_27_3725D8(void*, int);
    void* __register_global_object(void*, void*, void*);
    extern u8 lbl_96_bss_1060;
    extern unsigned char lbl_96_bss_1064[4];
    extern unsigned char lbl_96_bss_F1C[12];

    void* fn_96_204BC() {
        if ((signed char)lbl_96_bss_1060 == 0) {
            fn_27_3725C8(lbl_96_bss_1064);
            __register_global_object(
                lbl_96_bss_1064,
                (void*)fn_27_3725D8,
                lbl_96_bss_F1C
            );
            lbl_96_bss_1060 = 1;
        }
        return lbl_96_bss_1064;
    }
}
