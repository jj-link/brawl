#pragma force_active on
#include <ft/fighter.h>

class Work {
public:
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual bool method(unsigned int flag, void* modules);
};

struct Modules {
    char pad0[0x64];
    Work* work;
};

struct FighterObj {
    char pad0[0xD8];
    Modules* modules;
};

extern "C" bool fn_27_152098(void* self, FighterObj* fighter) {
    Fighter::Instance::Work::Flag flag = Fighter::Instance::Work::Flag_Speed_Damage;
    return fighter->modules->work->method(flag, fighter->modules);
}
