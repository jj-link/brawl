#pragma force_active on

typedef signed int s32;

class soArrayVectorCalcInterface;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
    soArrayVectorCalcInterface* a, s32 b, s32 c, s32 d);

class Foo {
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
    virtual void v29(s32) = 0;
};

extern "C" void fn_27_DBE30(Foo* self) {
    s32 b;
    s32 a = self->v27();
    b = self->v13();
    s32 c = self->v4();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (soArrayVectorCalcInterface*)((char*)self + 4), c, b, a);
    s32 d = self->v3();
    self->v29(d - 1);
}
