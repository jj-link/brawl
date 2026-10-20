#pragma force_active on
struct FighterA {
    int unk0;
    float unk4;
    float unk8;
};

struct FighterB {
    int unk0;
    float unk4;
};

extern "C" void fn_27_1DC540(FighterA* a, FighterB* b) {
    a->unk8 = a->unk8 * b->unk4;
}
