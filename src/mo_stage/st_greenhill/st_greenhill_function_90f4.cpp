#pragma force_active on
class soArrayVectorCalcInterface {
public:
    int m_dummy;
};

extern "C" void clear__23soArrayVectorCalculatorFR26soArrayVectorCalcInterface(soArrayVectorCalcInterface& calc);

class soArrayVectorCalculatorBase {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13() = 0;
    virtual void vf14() = 0;
    virtual void vf15() = 0;
    virtual void vf16() = 0;
    virtual void vf17() = 0;
    virtual void vf18() = 0;
    virtual void vf19() = 0;
    virtual void vf20() = 0;
    virtual void vf21() = 0;
    virtual void vf22() = 0;
    virtual void vf23() = 0;
    virtual void vf24() = 0;
    virtual void vf25() = 0;
    virtual void vf26() = 0;
    virtual void vf27() = 0;
    virtual void vf28() = 0;
    virtual void vf29(int flag) = 0;
    virtual void vf30() = 0;
    virtual void vf31() = 0;
    soArrayVectorCalcInterface m_calc;
};

extern "C" void fn_72_90F4(soArrayVectorCalculatorBase* self) {
    clear__23soArrayVectorCalculatorFR26soArrayVectorCalcInterface(self->m_calc);
    self->vf29(0);
}
