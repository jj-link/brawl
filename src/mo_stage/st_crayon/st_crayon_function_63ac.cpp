#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 4;
    signed int b : 2;
    unsigned int c : 26;
};

extern "C" int fn_56_63AC(S* s) {
    return s->b;
}
