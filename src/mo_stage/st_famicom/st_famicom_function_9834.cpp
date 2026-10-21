#pragma force_active on
typedef signed int s32;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, void* iface, s32 b, s32 l);

class Base {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual s32 d3();
    virtual void* d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual s32 d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual s32 d27();
    virtual void d28();
    virtual void d29(s32 n);
};

extern "C" void fn_68_9834(Base* self) {
    s32 b;
    s32 a = self->d27();
    b = self->d13();
    void* iface = self->d4();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, iface, b, a);
    s32 n = self->d3();
    self->d29(n - 1);
}
