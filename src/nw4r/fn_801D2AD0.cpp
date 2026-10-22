#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;

struct GlobalObj {
    u8 unk0;
    int unk4;
    void* unk8;
    void* unkC;
    int unk10;
    void* unk14;
    void* unk18;
};

extern "C" {
    extern u8 lbl_805A0620;
    extern GlobalObj lbl_804DD0EC;
    extern char lbl_804DD0E0[12];
    extern void fn_801D2B5C(void);
    void __register_global_object(void* obj, void* dtor, void* reg);
}

extern "C" GlobalObj* fn_801D2AD0(void) {
    if ((s8)lbl_805A0620 == 0) {
        void* p14;
        void* p8;
        lbl_804DD0EC.unk8 = 0;
        p14 = &lbl_804DD0EC.unk14;
        p8 = &lbl_804DD0EC.unk8;
        lbl_804DD0EC.unkC = 0;
        lbl_804DD0EC.unk14 = 0;
        lbl_804DD0EC.unk18 = 0;
        lbl_804DD0EC.unk0 = 0;
        lbl_804DD0EC.unk4 = 0;
        lbl_804DD0EC.unk8 = p8;
        lbl_804DD0EC.unkC = p8;
        lbl_804DD0EC.unk10 = 0;
        lbl_804DD0EC.unk14 = p14;
        lbl_804DD0EC.unk18 = p14;
        __register_global_object(&lbl_804DD0EC, (void*)fn_801D2B5C, lbl_804DD0E0);
        lbl_805A0620 = 1;
    }
    return &lbl_804DD0EC;
}
