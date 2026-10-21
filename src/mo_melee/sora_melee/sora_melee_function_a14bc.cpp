#pragma force_active on
typedef signed int s32;

class acCmdInterpreterStackData {};

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void*, s32, s32, s32);

template <class T>
class soArrayVectorAbstract {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual s32 size() = 0;
    virtual s32 isEmpty() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual s32 capacity() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual s32 getTopIndex() = 0;
    virtual void f28() = 0;
    virtual void setSize(s32) = 0;

    virtual void shift();
};

template <class T>
void soArrayVectorAbstract<T>::shift() {
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)this + 4, isEmpty(), capacity(), getTopIndex());
    setSize(size() - 1);
}

template class soArrayVectorAbstract<acCmdInterpreterStackData>;
