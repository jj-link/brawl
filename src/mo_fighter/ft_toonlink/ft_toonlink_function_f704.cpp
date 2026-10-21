#include <types.h>
#pragma force_active on

class StateTransition {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual int check(int);
    virtual void f15();
    virtual int kind(int);
};

class Effects {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void call(int, void*);
};

struct Modules {
    char pad0[0x70];
    Effects* effects;
    char pad74[0x34];
    StateTransition* transition;
};

struct Fighter {
    char pad0[0xD8];
    Modules* modules;
};

extern "C" void fn_121_F704(void*, Fighter* fighter) {
    StateTransition* transition = fighter->modules->transition;
    if (transition->check(0) != 0 && transition->kind(0) == 0x5B) {
        fighter->modules->effects->call(0x9B, fighter);
    }
}
