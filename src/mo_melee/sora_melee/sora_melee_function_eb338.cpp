#pragma force_active on
class Base {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual int v3() = 0;
    virtual void* v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual int v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual int v27() = 0;
    virtual void v28() = 0;
    virtual void v29(int n) = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
};

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, void* b, int c, int d);

extern "C" void fn_27_EB338(Base* self) {
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, self->v4(), self->v13(), self->v27());
    int n = self->v3();
    self->v29(n - 1);
}
