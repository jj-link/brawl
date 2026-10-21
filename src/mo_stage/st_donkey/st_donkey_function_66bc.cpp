#include <types.h>
#pragma force_active on

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, int b, int c, int d);

class Base {
public:
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual int v5() = 0;
    virtual int v6() = 0;
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

    char m_calc[1];
};

extern "C" void fn_50_66BC(Base* self) {
    s32 b;
    s32 a;
    a = self->v29();
    b = self->v15();
    s32 c = self->v6();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(self->m_calc, c, b, a);
    s32 n = self->v5();
    self->v31(n - 1);
}
