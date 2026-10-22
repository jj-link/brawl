#pragma force_active on

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
    void* a, void* b, int c, int d);

class C {
public:
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual int v5() = 0;
    virtual void* v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual int v15() = 0;
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
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual int v29() = 0;
    virtual void v30() = 0;
    virtual void v31(int n) = 0;
};

extern "C" void fn_68_75EC(C* self) {
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (char*)self + 4, self->v6(), self->v15(), self->v29());
    self->v31(self->v5() - 1);
}
