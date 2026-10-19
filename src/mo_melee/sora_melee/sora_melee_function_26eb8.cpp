#pragma force_active on
struct Inner {
    virtual void v0();
    virtual void* v1(void* p);
    virtual void v2();
    virtual void v3();
};

struct Outer {
    char pad[0x28];
    Inner* inner;
};

extern "C" void fn_27_2EF0C(void* a, void* b, int c);

extern "C" void fn_27_26EB8(Outer* self, void* a, void* b) {
    void* r = self->inner->v1(b);
    fn_27_2EF0C(r, a, 1);
}
