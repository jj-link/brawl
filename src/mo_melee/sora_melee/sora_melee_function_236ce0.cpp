#pragma force_active on
extern "C" const float lbl_27_rodata_38F0;
extern "C" char lbl_27_data_4C2E8[];

struct FnObj {
    int unk0;
    void* unk4;
    int unk8;
    char unkC;
    float unk10;
    float unk14;
};

extern "C" void fn_27_236CE0(FnObj* p, int p2, float p3) {
    float z = lbl_27_rodata_38F0;
    p->unk0 = 0;
    p->unk8 = p2;
    p->unkC = 0;
    p->unk4 = lbl_27_data_4C2E8;
    p->unk10 = p3;
    p->unk14 = z;
}
