#pragma force_active on
extern "C" void fn_802A7714(void*, int, int, void*, void*, void*);

extern "C" char lbl_80487188[];
extern "C" const float lbl_805A3EF8;

struct Vtable_Class_802A3994 {
    void* vtable;
    float f4;
    Vtable_Class_802A3994() : f4(lbl_805A3EF8) {}
};
class Class_802A3994 : public Vtable_Class_802A3994 {
public:
    float pad8[2];
    float vec[4];
    int i20;
    int pad24[3];
    Class_802A3994() {}
    ~Class_802A3994() {}
};

struct Tmp {
    int a;
    int b;
    float c;
    unsigned char d;
    float e[4];
    float f;
    float g;
    int h;
};

extern "C" void fn_802A9380(void* a, int b, int c, Tmp* d, int e, int f) {
    Tmp tmp __attribute__((aligned(16)));
    tmp.a = d->a;
    tmp.b = d->b;
    tmp.c = d->c;
    tmp.d = d->d;
    tmp.e[0] = d->e[0];
    tmp.e[1] = d->e[1];
    tmp.e[2] = d->e[2];
    tmp.e[3] = d->e[3];
    tmp.f = d->f;
    tmp.g = d->g;
    tmp.h = d->h;
    tmp.e[0] = -d->e[0];
    tmp.e[1] = -d->e[1];
    tmp.e[2] = -d->e[2];
    tmp.e[3] = -d->e[3];
    Class_802A3994 local1 __attribute__((aligned(16)));
    local1.vtable = lbl_80487188;
    local1.vec[0] = d->e[0];
    local1.vec[1] = d->e[1];
    local1.vec[2] = d->e[2];
    local1.vec[3] = d->e[3];
    local1.i20 = e;
    Class_802A3994* p1 = &local1;
    if (f != 0) {
        Class_802A3994 local0 __attribute__((aligned(16)));
        Class_802A3994* p0 = &local0;
        p0->vtable = lbl_80487188;
        local0.vec[0] = d->e[0];
        local0.vec[1] = d->e[1];
        local0.vec[2] = d->e[2];
        local0.vec[3] = d->e[3];
        local0.i20 = f;
        fn_802A7714(a, c, b, &tmp, p1, p0);
    } else {
        fn_802A7714(a, c, b, &tmp, p1, 0);
    }
}