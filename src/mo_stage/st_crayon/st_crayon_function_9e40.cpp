#pragma force_active on
class soArrayVectorCalcInterface;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
    void*, soArrayVectorCalcInterface*, int, int);

class Obj {
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
    virtual int v27();
    virtual void v28();
    virtual void v29(int n);
};

extern "C" void fn_56_9E40(Obj* self) {
    int b;
    int a;
    a = self->v27();
    b = self->v13();
    soArrayVectorCalcInterface* c = self->v4();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (char*)self + 4, c, b, a);
    int n = self->v3();
    self->v29(n - 1);
}
