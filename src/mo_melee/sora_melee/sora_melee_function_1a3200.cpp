#pragma force_active on
struct fn_27_1A3200_Obj {
    char *unk0;
    char *unk4;
    unsigned int unk8;
};

extern char lbl_27_data_36A78[];

extern "C" {
void fn_27_1A3200(fn_27_1A3200_Obj *p) {
    char *base = lbl_27_data_36A78;
    unsigned int flag = p->unk8;
    p->unk0 = base;
    p->unk4 = base + 0x48;
    p->unk8 = flag & 1;
}
}
