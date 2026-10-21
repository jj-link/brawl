#pragma force_active on
typedef signed int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void*, s32, s32, s32);

class MyArray {
public:
    virtual void p0() = 0;
    virtual void p1() = 0;
    virtual void p2() = 0;
    virtual s32 size() = 0;
    virtual s32 isEmpty() = 0;
    virtual void p5() = 0;
    virtual void p6() = 0;
    virtual void p7() = 0;
    virtual void p8() = 0;
    virtual void p9() = 0;
    virtual void p10() = 0;
    virtual void p11() = 0;
    virtual void p12() = 0;
    virtual s32 capacity() = 0;
    virtual void p14() = 0;
    virtual void p15() = 0;
    virtual void p16() = 0;
    virtual void p17() = 0;
    virtual void p18() = 0;
    virtual void p19() = 0;
    virtual void p20() = 0;
    virtual void p21() = 0;
    virtual void p22() = 0;
    virtual void p23() = 0;
    virtual void p24() = 0;
    virtual void p25() = 0;
    virtual void p26() = 0;
    virtual void p27() = 0;
    virtual s32 getLastIndex() = 0;
    virtual void setSize(s32) = 0;
};

extern "C" void fn_66_E028(MyArray* self) {
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (void*)((char*)self + 4),
        self->isEmpty(),
        self->capacity(),
        self->getLastIndex()
    );
    self->setSize(self->size() - 1);
}
