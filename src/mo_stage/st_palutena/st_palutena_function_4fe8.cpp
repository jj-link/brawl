#pragma force_active on
struct S {
    int a;
    int b;
    int c;
};

extern "C" int fn_67_4FE8(S* s) {
    return s->c >> 30;
}
