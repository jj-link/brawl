#include <types.h>
#pragma force_active on

class A {
public:
    virtual ~A();
    virtual void third(int);    // slot 1  -> 0x0C
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual A* first();         // slot 18 -> 0x50
    virtual void p19();
    virtual A* second(int);     // slot 20 -> 0x58
};

extern "C" void fn_27_8ECC4(A* a, int b, int c) {
    A* r = a->first();
    if (r == (A*)1) {
        A* r2 = a->second(b);
        r2->third(c);
    }
}
