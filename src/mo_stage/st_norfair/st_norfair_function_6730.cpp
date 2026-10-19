#pragma force_active on
struct S {
    int a;
    int b;
    int f : 2;
};

extern "C" int fn_54_6730(S* s) {
    return s->f;
}
