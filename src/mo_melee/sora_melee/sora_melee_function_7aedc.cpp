#pragma force_active on
typedef signed int s32;

class soArrayVectorCalcInterface {
public:
    virtual void substitution(s32, s32) = 0;
    virtual void onFull() = 0;
    virtual void offFull() = 0;
    virtual void setTopIndex(s32) = 0;
    virtual void setLastIndex(s32) = 0;
    virtual ~soArrayVectorCalcInterface() { }
};

class soArrayVectorCalculator {
public:
    static void pop(soArrayVectorCalcInterface& ifc, bool empty, long capacity, long lastIndex);
};

class SoArrayVectorLike {
public:
    virtual void d0() = 0;
    virtual void d1() = 0;
    virtual void d2() = 0;
    virtual long f5() = 0;
    virtual bool f6() = 0;
    virtual void d5() = 0;
    virtual void d6() = 0;
    virtual void d7() = 0;
    virtual void d8() = 0;
    virtual void d9() = 0;
    virtual void d10() = 0;
    virtual void d11() = 0;
    virtual void d12() = 0;
    virtual long f15() = 0;
    virtual void d14() = 0;
    virtual void d15() = 0;
    virtual void d16() = 0;
    virtual void d17() = 0;
    virtual void d18() = 0;
    virtual void d19() = 0;
    virtual void d20() = 0;
    virtual void d21() = 0;
    virtual void d22() = 0;
    virtual void d23() = 0;
    virtual void d24() = 0;
    virtual void d25() = 0;
    virtual void d26() = 0;
    virtual void d27() = 0;
    virtual long f30() = 0;
    virtual void f31(long) = 0;
};

extern "C" void fn_27_7AEDC(SoArrayVectorLike* self) {
    long cap;
    long last;
    last = self->f30();
    cap = self->f15();
    bool empty = self->f6();
    soArrayVectorCalculator::pop(*(soArrayVectorCalcInterface*)((char*)self + 4), empty, cap, last);
    long size = self->f5();
    self->f31(size - 1);
}
