#pragma force_active on
typedef signed int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, void* iface, s32 a, s32 b);

class Calc {
public:
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual s32 v5() = 0;
    virtual void* v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual s32 v15() = 0;
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
    virtual void v29() = 0;
    virtual s32 v30() = 0;
    virtual void v31(s32 n) = 0;
};

extern "C" void fn_27_14F5EC(Calc* self) {
    s32 r31;
    s32 r30;
    r30 = self->v30();
    r31 = self->v15();
    void* it = self->v6();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((void*)((char*)self + 4), it, r31, r30);
    s32 n = self->v5();
    self->v31(n - 1);
}
