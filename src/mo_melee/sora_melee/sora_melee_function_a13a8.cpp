#pragma force_active on
#include <ac/ac_cmd_interpreter.h>

template <>
class soArrayVectorAbstract<acCmdInterpreterStackData> {
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
    virtual acCmdInterpreterStackData* v70(int);
    virtual int v74();
    virtual int v78();
    virtual void v7C(int);

    int calc;
    void unshift(const acCmdInterpreterStackData&);
};

void soArrayVectorAbstract<acCmdInterpreterStackData>::unshift(const acCmdInterpreterStackData& value) {
    int index = soArrayVectorCalculator::unshift(
        reinterpret_cast<soArrayVectorCalcInterface&>(calc), v40(), v3C(), v74(), v78());
    acCmdInterpreterStackData* destination = v70(index);
    *destination = value;
    v7C(size() + 1);
}
