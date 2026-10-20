#pragma force_active on
struct S {
    int a;
    int b;
    int f : 2;
};

extern "C" int fn_67_50B0(S* s) {
    return s->f;
}
