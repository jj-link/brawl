#pragma force_active on
typedef signed int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, void* ref, s32 b, s32 l);

class Obj {
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
    virtual void v27() = 0;
    virtual s32 v28() = 0;
    virtual void v29(s32 x) = 0;
};

extern "C" void fn_27_E7BA0(Obj* self) {
    s32 t15;
    s32 t30 = self->v28();
    t15 = self->v13();
    void* r = self->v4();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, r, t15, t30);
    self->v29(self->v3() - 1);
}
