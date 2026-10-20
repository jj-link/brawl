#include <types.h>
#pragma force_active on

class soSubBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class soOuterWork {
public:
    u8 m_pad[0x10];
    soSubBase m_sub;
};

extern "C" {
void fn_27_1B1588(soOuterWork* work) {
    work->m_sub.f3();
}
}
