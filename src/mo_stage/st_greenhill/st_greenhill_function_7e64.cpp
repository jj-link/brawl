#pragma force_active on
class soArrayVectorCalcInterface;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, soArrayVectorCalcInterface* iface, int b, long a);

class Self {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual soArrayVectorCalcInterface* v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int v13();
    virtual void v14();
    virtual void v15();
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
    virtual int v28();
    virtual void v29(int x);
};

extern "C" void fn_72_7E64(Self* self) {
    int t31;
    int t30;
    t30 = self->v28();
    t31 = self->v13();
    soArrayVectorCalcInterface* r = self->v4();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, r, t31, t30);
    self->v29(self->v3() - 1);
}
