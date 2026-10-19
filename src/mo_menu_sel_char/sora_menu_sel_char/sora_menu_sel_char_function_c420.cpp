#pragma force_active on
class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11(void* a, void* b);
    virtual void f12();
    virtual void f13();
    char pad[0xe4 - 4];
    void* f_e4;
};

struct Sub {
    char pad[0x10];
    void* val;
};

struct Outer {
    char pad0[0x6c];
    Inner* inner;
    char pad2[0x13c - 0x70];
    Sub* arr[1];
};

extern "C" void fn_10_C420(Outer* self, int idx) {
    Inner* in = self->inner;
    in->f11(in->f_e4, self->arr[idx]->val);
}
