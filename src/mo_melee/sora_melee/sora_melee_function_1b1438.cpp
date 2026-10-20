#include <types.h>
#pragma force_active on

class fnPad27 {
public:
    int m0, m1, m2, m3;
};

class fnIface27 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

class fnOuter27 : public fnPad27, public fnIface27 {
public:
    virtual void f5();
};

extern "C" {
void fn_27_1B1438(fnOuter27* p) {
    fnIface27& i = *p;
    i.f3();
}
}
