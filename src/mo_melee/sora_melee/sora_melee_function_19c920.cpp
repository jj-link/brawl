#pragma force_active on
extern "C" char lbl_27_data_1F88[];

struct Obj {
    int unk0;
    void* unk4;
    int unk8;
    int unkC;
    int unk10;
};

extern "C" void fn_27_19C920(Obj* p) {
    p->unk8 = 0;
    p->unk4 = lbl_27_data_1F88;
    p->unkC = 0;
    p->unk10 = 0;
}
