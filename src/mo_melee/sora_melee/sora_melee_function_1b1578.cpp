#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
};

class Outer {
public:
    u8 pad[0x10];
    Inner inner;
};

extern "C" int fn_27_1B1578(Outer* p) {
    Inner* q = &p->inner;
    return q->f3();
}
