#include <types.h>
#pragma force_active on

extern "C" void fn_27_60D0(void);

class NonPolyBase {
public:
    int unk0;
    int unk4;
};

class Subject : public NonPolyBase {
public:
    virtual void p0();
    virtual void p1();
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
    virtual void proc(void* fighter);
};

class Owner {
public:
    char pad[0x8d0];
    Subject* m_subject;
};

extern "C" void fn_27_28951C(Owner* owner) {
    fn_27_60D0();
    owner->m_subject->proc(owner);
}
