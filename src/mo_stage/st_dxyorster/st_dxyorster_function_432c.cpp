#pragma force_active on

class soArrayVectorCalcInterface;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, soArrayVectorCalcInterface* iface, int b, int c);

class Calc {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int f5();
    virtual soArrayVectorCalcInterface* f6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual int f15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual int f29();
    virtual void v30();
    virtual void f31(int n);
};

extern "C" void fn_76_432C(Calc* self) {
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, self->f6(), self->f15(), self->f29());
    self->f31(self->f5() - 1);
}
