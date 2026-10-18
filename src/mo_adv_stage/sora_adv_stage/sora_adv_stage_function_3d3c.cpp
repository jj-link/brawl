#pragma force_active on
struct S {
    int a;
    int b;
};

struct T {
    int a;
    int b;
    S* c;
};

extern "C" int fn_40_3D3C(T *t) {
    return t->c->b;
}
