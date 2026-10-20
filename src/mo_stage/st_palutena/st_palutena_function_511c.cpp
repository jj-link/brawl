#pragma force_active on
struct Unk {
    char pad[8];
    unsigned int a : 6;
    unsigned int b : 1;
};

extern "C" unsigned int fn_67_511C(Unk* p) {
    return p->b;
}
