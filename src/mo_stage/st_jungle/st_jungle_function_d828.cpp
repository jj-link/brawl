#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 9;
    unsigned int b : 1;
};

extern "C" unsigned int fn_51_D828(S* s) {
    return s->b;
}
