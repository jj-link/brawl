#pragma force_active on
extern char lbl_80454EA8[];
extern const float lbl_805A2020;
extern const float lbl_805A2024;
extern const float lbl_805A2028;
extern const float lbl_805A202C;

struct Obj {
    int unk0;
    char* unk4;
    int unk8;
    float unkC;
    unsigned char flag : 1;
    unsigned char rest : 7;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
};

extern "C" void fn_800A6598(Obj* p) {
    p->unk0 = 0;
    p->unk4 = lbl_80454EA8;
    p->unk8 = 0;
    p->unkC = lbl_805A2020;
    p->unk14 = lbl_805A2024;
    p->unk24 = lbl_805A2028;
    p->flag = 0;
    p->unk18 = lbl_805A202C;
    p->unk1C = lbl_805A202C;
    p->unk20 = lbl_805A202C;
}
