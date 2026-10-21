#pragma force_active on

struct S {
    int a;
    int b;
    unsigned x : 30;
    unsigned y : 1;
    unsigned z : 1;
};

extern "C" unsigned fn_27_1A36E0(S* s) {
    return s->y;
}
