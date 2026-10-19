#pragma force_active on
extern "C" void fn_116_8494(void* obj, void* a, int b, void* c, int d, void* e, int f);

struct P { int a; int b; };
class D : public P {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
};

extern "C" void* fn_116_8994(void* self) {
    char* s = (char*)self;
    fn_116_8494(s + 0x1c0, self, 0x4d, s + 0x134, 0x20, s + 0x1b4, 3);
    D* d = (D*)(s + 0x1c0);
    d->m25();
    return self;
}
