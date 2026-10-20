#pragma force_active on
struct S {
    int a;
    int b;
    int f : 2;
};

extern "C" int fn_71_F17C(S* s) {
    return s->f;
}
