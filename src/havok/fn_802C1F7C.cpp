#pragma force_active on

extern "C" void fn_802C15D0(void*, void*, void*, void*, void*, void*);
extern "C" char lbl_80487188[];
extern "C" const float lbl_805A3FA0;

struct Vtable_Class_802A3994 {
    void* vtable;
    float f;
    Vtable_Class_802A3994() : f(lbl_805A3FA0) { vtable = lbl_80487188; }
};

struct Vec {
    float x, y, z, w;
    Vec(const Vec& o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};

struct Input {
    int a, b;
    float c;
    char d;
    float e, f, g, h, i, j;
    int k;
    Input(const Input& o) : a(o.a), b(o.b), c(o.c), d(o.d), e(o.e), f(o.f), g(o.g), h(o.h), i(o.i), j(o.j), k(o.k) {}
};

class Class_802A3994 : public Vtable_Class_802A3994 {
public:
    char pad[8];
    Vec vec;
    void* ptr;
    Class_802A3994(const Vec& v, void* p) : vec(v), ptr(p) {}
    Class_802A3994(const Vec& v) : vec(v) {}
    ~Class_802A3994() {}
};

extern "C" void fn_802C1F7C(void* a, void* b, void* c, Input* in, void* d, void* e) {
    Input copy __attribute__((aligned(16))) = *in;
    copy.e = -in->e;
    copy.f = -in->f;
    copy.g = -in->g;
    copy.h = -in->h;
    Class_802A3994 local1 __attribute__((aligned(16)))(*(Vec*)&in->e, d);
    Class_802A3994* p = &local1;
    if (e) {
        Class_802A3994 local0 __attribute__((aligned(16)))(*(Vec*)&in->e);
        Class_802A3994* q = &local0;
        q->ptr = e;
        fn_802C15D0(a, c, b, &copy, p, q);
    } else {
        fn_802C15D0(a, c, b, &copy, p, 0);
    }
}
