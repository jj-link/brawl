#pragma force_active on
extern "C" float lbl_805A3168;
extern "C" char lbl_804659B0[];

struct Obj {
    void* unk0;
    int unk4;
    int unk8;
    int unkC;
    float unk10;
    int unk14;
    int unk18;
    short unk1C;
};

extern "C" void fn_8018B3C0(Obj* p) {
    float f = lbl_805A3168;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unkC = 0;
    p->unk10 = f;
    p->unk0 = lbl_804659B0;
    p->unk14 = 0;
    p->unk18 = 0;
    p->unk1C = 0;
}
