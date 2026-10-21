#pragma force_active on
typedef signed int s32;

class soArrayVectorCalcInterface;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, soArrayVectorCalcInterface* ref, s32 a, s32 b);

class soArrayVectorCalculator {
public:
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual void s4() = 0;
    virtual s32 v5() = 0;
    virtual soArrayVectorCalcInterface* v6() = 0;
    virtual void s7() = 0;
    virtual void s8() = 0;
    virtual void s9() = 0;
    virtual void s10() = 0;
    virtual void s11() = 0;
    virtual void s12() = 0;
    virtual void s13() = 0;
    virtual void s14() = 0;
    virtual s32 v15() = 0;
    virtual void s16() = 0;
    virtual void s17() = 0;
    virtual void s18() = 0;
    virtual void s19() = 0;
    virtual void s20() = 0;
    virtual void s21() = 0;
    virtual void s22() = 0;
    virtual void s23() = 0;
    virtual void s24() = 0;
    virtual void s25() = 0;
    virtual void s26() = 0;
    virtual void s27() = 0;
    virtual void s28() = 0;
    virtual s32 v29() = 0;
    virtual void s30() = 0;
    virtual void v31(s32 n) = 0;
    void* m_sub;
};

extern "C" void fn_27_122DE0(soArrayVectorCalculator* self) {
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(&self->m_sub, self->v6(), self->v15(), self->v29());
    s32 n = self->v5();
    self->v31(n - 1);
}
