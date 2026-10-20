#pragma force_active on
struct S {
    int a;
    int b;
    int f : 2;
};

extern "C" int fn_68_D188(S* s) {
    return s->f;
}
