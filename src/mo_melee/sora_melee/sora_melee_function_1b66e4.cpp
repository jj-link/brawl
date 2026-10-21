#pragma force_active on

typedef signed int s32;
class soArrayVectorCalcInterface;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, soArrayVectorCalcInterface* iface, s32 b, s32 c);

class Obj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual s32 m13();
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
    virtual void m26();
    virtual s32 m27();
    virtual void m28();
    virtual void m29(s32 x);
};

extern "C" void fn_27_1B66E4(Obj* self) {
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, (soArrayVectorCalcInterface*)self->m4(), self->m13(), self->m27());
    self->m29(self->m3() - 1);
}
