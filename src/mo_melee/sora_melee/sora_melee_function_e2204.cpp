#pragma force_active on
extern "C" void fn_27_AB2E0(void* a, void* b);

class soWorkBase {
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
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void* f26(void* p);
};

extern "C" {
void fn_27_E2204(soWorkBase* self, void* x, void* p) {
    void* a = self->f26(x);
    void* b = self->f26(p);
    fn_27_AB2E0(b, a);
}
}
