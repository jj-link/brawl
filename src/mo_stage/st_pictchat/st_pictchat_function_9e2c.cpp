#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 12;
    unsigned int b : 1;
};

extern "C" unsigned int fn_73_9E2C(S* s) {
    return s->b;
}
