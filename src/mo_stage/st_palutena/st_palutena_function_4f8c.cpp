#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 6;
    unsigned int b : 1;
};

extern "C" unsigned int fn_67_4F8C(S* p) {
    return p->b;
}
