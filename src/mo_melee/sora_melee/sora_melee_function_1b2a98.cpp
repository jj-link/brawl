#pragma force_active on

class wnPikminPikmin;
struct soArrayVectorCalcInterface {};

extern "C" int unshift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
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
    void unshift(const T&);
};

template <>
void soArrayVectorAbstract<wnPikminPikmin*>::unshift(wnPikminPikmin* const& value) {
    wnPikminPikmin** dest = this->v70(
        unshift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
            this->calc, this->v40(), this->v3C(), this->v74(), this->v78()));
    *dest = value;
    this->v7C(this->size() + 1);
}
