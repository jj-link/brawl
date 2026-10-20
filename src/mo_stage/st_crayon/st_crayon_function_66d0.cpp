#pragma force_active on
struct S {
    char pad[8];
    int a : 4;
    int b : 4;
};

extern "C" int fn_56_66D0(S* s) {
    return s->b;
}
