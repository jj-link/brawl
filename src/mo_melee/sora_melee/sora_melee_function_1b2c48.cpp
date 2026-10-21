#pragma force_active on

class wnPikminPikmin;
struct soArrayVectorCalcInterface {};

extern "C" int push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
    soArrayVectorCalcInterface&, bool, long, long, long);

template <class T>
class soArrayVectorAbstract {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual int size();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual int v3C();
    virtual bool v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual T* v70(int);
    virtual int v74();
    virtual int v78();
    virtual void v7C(int);

    soArrayVectorCalcInterface calc;
    void push(const T&);
};

template <>
void soArrayVectorAbstract<wnPikminPikmin*>::push(wnPikminPikmin* const& value) {
    int index = push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        calc, v40(), v3C(), v74(), v78());
    wnPikminPikmin** destination = v70(index);
    *destination = value;
    v7C(size() + 1);
}
