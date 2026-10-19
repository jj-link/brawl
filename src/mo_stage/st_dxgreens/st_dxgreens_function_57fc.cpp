#pragma force_active on
struct S {
    int a;
    int b;
    int f : 6;
};

extern "C" int fn_79_57FC(S* s) {
    return s->f;
}
