#pragma force_active on
struct Unk47 {
    char pad[8];
    unsigned int a : 12;
    unsigned int b : 1;
};

extern "C" unsigned int fn_47_4F68(Unk47* p) {
    return p->b;
}
