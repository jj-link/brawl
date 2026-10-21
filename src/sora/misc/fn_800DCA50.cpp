#pragma force_active on
struct S {
    char unk_0[0x70];
    int unk_70;
};

struct T {
    char unk_0[0x70];
    S* unk_70;
};

extern "C" int fn_800DCA50(T *t) {
    return t->unk_70->unk_70;
}
