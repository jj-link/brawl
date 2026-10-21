#pragma force_active on
extern "C" float lbl_805A1860;

struct Obj {
    int unk0;
    int unk4;
    unsigned char unk8;
    unsigned char unk9;
    unsigned char unkA;
    unsigned char pad[1];
    float unkC;
};

extern "C" void fn_8004E858(Obj** arg0) {
    Obj* p = *arg0;
    float f = lbl_805A1860;
    p->unk4 = 0;
    p->unkC = f;
    p->unkA = 0;
    p->unk8 = 1;
    p->unk9 = 1;
}
