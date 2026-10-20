#pragma force_active on
extern "C" {
extern char lbl_27_data_19BF8[];
}

struct fn_27_D36B8_S {
    void *unk0;
    void *unk4;
    unsigned int unk8;
};

extern "C" void fn_27_D36B8(fn_27_D36B8_S *p) {
    unsigned int v = p->unk8;
    char *base = lbl_27_data_19BF8;
    p->unk0 = base;
    p->unk4 = base + 0x48;
    p->unk8 = v & 0xFFFF;
}
