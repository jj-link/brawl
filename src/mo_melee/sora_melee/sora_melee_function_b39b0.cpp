#pragma force_active on
typedef unsigned int u32;

struct Inner {
    virtual void f0();
    virtual void* f1(void*, u32);
};

struct Outer {
    char pad[0x18];
    Inner* inner;
};

extern "C" void fn_27_B1EDC(void*, void*, u32);

extern "C" void fn_27_B39B0(Outer* self, void* a, u32 b, void* c) {
    void* r = self->inner->f1(c, b);
    fn_27_B1EDC(r, a, b);
}
