#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 6;
    unsigned int b : 1;
    unsigned int c : 25;
};

extern "C" unsigned int fn_54_663C(S* s) {
    return s->b;
}
