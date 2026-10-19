#pragma force_active on
struct GlobalObject {
    signed char flag;
    char pad[3];
    void *vtable;
};

extern "C" {
extern signed char lbl_61_bss_3C;
extern GlobalObject lbl_61_bss_40;
extern char lbl_61_data_2238[];
extern char lbl_61_data_21E0[];
extern char lbl_61_bss_18[];
void *fn_61_970C(void *, int);
void *__register_global_object(void *, void *, void *);
}

extern "C" GlobalObject *fn_61_9648() {
    if (!lbl_61_bss_3C) {
        lbl_61_bss_40.vtable = lbl_61_data_2238;
        lbl_61_bss_40.flag = 1;
        lbl_61_bss_40.vtable = lbl_61_data_21E0;
        __register_global_object(&lbl_61_bss_40,
                                 (void *)fn_61_970C,
                                 lbl_61_bss_18);
        lbl_61_bss_3C = 1;
    }
    return &lbl_61_bss_40;
}
