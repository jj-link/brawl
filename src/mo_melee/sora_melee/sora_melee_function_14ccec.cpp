#pragma force_active on
extern char lbl_27_data_2BF70[];

struct Obj {
    void* vtbl;
    unsigned char unk4[0x174];
    unsigned int unk178;
};

extern "C" void fn_27_C2E38(Obj*);

extern "C" Obj* fn_27_14CCEC(Obj* p) {
    fn_27_C2E38(p);
    p->unk178 = 0;
    p->vtbl = lbl_27_data_2BF70;
    return p;
}
