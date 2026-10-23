#pragma force_active on
struct S {
    int unk_0[0x10];
    int unk_40;
};

struct T {
    S* unk_0;
};

extern "C" int fn_801077C4(T* t) {
    return t->unk_0->unk_40;
}
