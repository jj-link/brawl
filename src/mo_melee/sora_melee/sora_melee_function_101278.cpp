#pragma force_active on

typedef signed int s32;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
    void* a, s32 b, s32 c, s32 d);

class MyClass {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual s32 v20();
    virtual s32 v24();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual s32 v60();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual s32 v116();
    virtual void p28();
    virtual void v124(s32);
};

extern "C" void fn_27_101278(MyClass* self) {
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (char*)self + 4, self->v24(), self->v60(), self->v116());
    s32 w = self->v20();
    self->v124(w - 1);
}
