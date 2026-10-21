#pragma force_active on
typedef signed int s32;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, void* b, s32 c, s32 d);

class FnObj {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual s32 v3() = 0;
    virtual void* v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual s32 v13() = 0;
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
    virtual s32 v27() = 0;
    virtual void v28() = 0;
    virtual void v29(s32 x) = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
};

extern "C" void fn_27_92900(FnObj* self) {
    s32 t3c;
    s32 t74;
    t74 = self->v27();
    t3c = self->v13();
    void* t18 = self->v4();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, t18, t3c, t74);
    s32 t14 = self->v3();
    self->v29(t14 - 1);
}
