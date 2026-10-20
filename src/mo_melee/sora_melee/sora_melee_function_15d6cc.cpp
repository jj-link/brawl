#pragma force_active on
struct FnA {
    int unk0;
    int unk4;
    int unk8;
    float unkC;
};

struct FnB {
    int unk0;
    float unk4;
};

extern "C" void fn_27_15D6CC(FnA *a, FnB *b)
{
    a->unkC = a->unkC * b->unk4;
}
