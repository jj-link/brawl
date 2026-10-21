#pragma force_active on

extern "C" {
void __register_global_object(void *object, void *destructor, void *chain);
void *fn_77_3090(void *p, int n);

extern char lbl_77_data_F58[];
extern char lbl_77_data_F00[];
extern char lbl_77_bss_3C;
extern char lbl_77_bss_18;

struct DxgardenObj {
    unsigned char c;
    void *p;
};
extern DxgardenObj lbl_77_bss_40;
}

extern "C" void *fn_77_2FCC(void) {
    if (!lbl_77_bss_3C) {
        lbl_77_bss_40.p = lbl_77_data_F58;
        lbl_77_bss_40.c = 1;
        lbl_77_bss_40.p = lbl_77_data_F00;
        __register_global_object(&lbl_77_bss_40, fn_77_3090, &lbl_77_bss_18);
        lbl_77_bss_3C = 1;
    }
    return &lbl_77_bss_40;
}
