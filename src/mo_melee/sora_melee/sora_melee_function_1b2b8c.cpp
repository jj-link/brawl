#pragma force_active on
extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, int b, int c, int d);

class wnPikminPikmin;

template <class T>
class soArrayVectorAbstract {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
    virtual int f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual int f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual int f27();
    virtual void f28();
    virtual void f29(int x);
    virtual void f30();
    virtual void f31();
    void shift();
};

template <class T>
void soArrayVectorAbstract<T>::shift() {
    int b;
    int a;
    a = f27();
    b = f13();
    int c = f4();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)this + 4, c, b, a);
    int d = f3();
    f29(d - 1);
}

template class soArrayVectorAbstract<wnPikminPikmin*>;
