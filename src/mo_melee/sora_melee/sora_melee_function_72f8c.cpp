#pragma force_active on
typedef int s32;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, int b, int c, int d);

class Obj {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual s32 v3() = 0;
    virtual s32 v4() = 0;
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
};

extern "C" void fn_27_72F8C(Obj* self) {
    s32 y;
    s32 x;
    x = self->v27();
    y = self->v13();
    s32 r4 = self->v4();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, r4, y, x);
    s32 n = self->v3();
    self->v29(n - 1);
}
