#include <types.h>
#pragma force_active on

class SoData {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

struct Elem {
    u32 a;
    u32 b;
};

class SoQueue {
public:
    virtual int q0();
    virtual int q1();
    virtual int q2();
    virtual int q3();
    virtual int q4();
    SoData* m_04;
    Elem* m_08;
    s32 m_0C;
};

extern "C" void fn_27_210EC(SoQueue* self) {
    if (self->q4())
        return;
    if (self->m_0C > 0) {
        self->m_0C--;
        if (self->m_0C <= 0)
            self->m_08 = 0;
        else
            self->m_08++;
    } else {
        if (self->m_04)
            self->m_04->m6();
    }
}
