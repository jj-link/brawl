#pragma force_active on
extern "C" void fn_802C9A8C(void*, void*, void*, void*, void*, void*);
extern "C" char lbl_80487188[];
extern "C" const float lbl_805A3FF4;
struct Vtable_Class_802A3994 {
    void* vtable; float f; char pad[8]; float x, y, z, w; void* ptr;
    Vtable_Class_802A3994() : f(lbl_805A3FF4) { vtable = lbl_80487188; }
};
class Class_802A3994 : public Vtable_Class_802A3994 {
public: Class_802A3994() {} ~Class_802A3994() {}
};
struct Data {
    int a, b; float c; unsigned char d; float x, y, z, w, e, f; int g;
    Data(const Data& o) : a(o.a), b(o.b), c(o.c), d(o.d), x(o.x), y(o.y), z(o.z), w(o.w), e(o.e), f(o.f), g(o.g) {}
};
extern "C" void fn_802CA32C(void* a, void* b, void* c, Data* d, void* e, void* f) {
    Data copy = *d;
    copy.x = -d->x; copy.y = -d->y; copy.z = -d->z; copy.w = -d->w;
    Class_802A3994 local1 __attribute__((aligned(16)));
    Class_802A3994* p = &local1;
    local1.x = d->x; local1.y = d->y; local1.z = d->z; local1.w = d->w; local1.ptr = e;
    if (f) {
        Class_802A3994 local0 __attribute__((aligned(16)));
        Class_802A3994* q = &local0;
        q->x = d->x; q->y = d->y; q->z = d->z; q->w = d->w; q->ptr = f;
        fn_802C9A8C(a, c, b, &copy, p, q);
    } else {
        fn_802C9A8C(a, c, b, &copy, p, 0);
    }
}
