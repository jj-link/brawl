#pragma force_active on
extern "C" void clear__23soArrayVectorCalculatorFR26soArrayVectorCalcInterface(void* calc);

class soVirtualBase {
public:
    virtual void vf0(int);
    virtual void vf1(int);
    virtual void vf2(int);
    virtual void vf3(int);
    virtual void vf4(int);
    virtual void vf5(int);
    virtual void vf6(int);
    virtual void vf7(int);
    virtual void vf8(int);
    virtual void vf9(int);
    virtual void vf10(int);
    virtual void vf11(int);
    virtual void vf12(int);
    virtual void vf13(int);
    virtual void vf14(int);
    virtual void vf15(int);
    virtual void vf16(int);
    virtual void vf17(int);
    virtual void vf18(int);
    virtual void vf19(int);
    virtual void vf20(int);
    virtual void vf21(int);
    virtual void vf22(int);
    virtual void vf23(int);
    virtual void vf24(int);
    virtual void vf25(int);
    virtual void vf26(int);
    virtual void vf27(int);
    virtual void vf28(int);
    virtual void vf29(int);
    virtual void vf30(int);
    virtual void vf31(int);
};

class soSelf : public soVirtualBase {
public:
    void* m_calc;
};

extern "C" void fn_27_E8D94(soSelf* self) {
    clear__23soArrayVectorCalculatorFR26soArrayVectorCalcInterface((void*)&self->m_calc);
    self->vf29(0);
}
