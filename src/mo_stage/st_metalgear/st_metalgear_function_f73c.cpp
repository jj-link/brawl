#pragma force_active on
struct S {
    int a;
    int b;
    int c;
};

extern "C" int fn_71_F73C(S* s) {
    return s->c >> 28;
}
