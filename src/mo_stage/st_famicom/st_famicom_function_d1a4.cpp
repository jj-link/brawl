#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 6;
    unsigned int b : 1;
};

extern "C" unsigned int fn_68_D1A4(S* s) {
    return s->b;
}
