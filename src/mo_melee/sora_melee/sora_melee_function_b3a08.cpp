#pragma force_active on
typedef unsigned int u32;

struct Vt {
    virtual void f0();
    virtual void* f1(void* p1, void* p2);
    virtual void f2();
    virtual void f3();
};

struct Self {
    int pad[6];
    Vt* obj;
};

extern "C" void fn_27_B2030(void* r, void* a, void* b);

extern "C" void fn_27_B3A08(Self* self, void* a, void* b, void* c) {
    fn_27_B2030(self->obj->f1(c, b), a, b);
}
