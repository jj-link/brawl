#pragma force_active on
class Module {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void disable(int);
    virtual int isEnabled(int);
};

struct Modules {
    unsigned char padding[0x54];
    Module* module;
};

struct Fighter {
    unsigned char padding[0xd8];
    Modules* modules;
};

extern "C" void fn_27_18EE70(void*, Fighter* fighter, int status) {
    switch (status) {
    case 248:
    case 249:
        return;
    default:
        break;
    }

    if (fighter->modules->module->isEnabled(4)) {
        fighter->modules->module->disable(4);
    }
}
