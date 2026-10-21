#pragma force_active on

struct ControlModule {
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void reserved3();
    virtual void reserved4();
    virtual void reserved5();
    virtual void reserved6();
    virtual void reserved7();
    virtual void reserved8();
    virtual void reserved9();
    virtual void reserved10();
    virtual void reserved11();
    virtual void reserved12();
    virtual void reserved13();
    virtual void reserved14();
    virtual void reserved15();
    virtual void reserved16();
    virtual void reserved17();
    virtual float getStickY();
    virtual void reserved19();
    virtual void reserved20();
    virtual void reserved21();
    virtual void reserved22();
    virtual void reserved23();
    virtual void reserved24();
    virtual void reserved25();
    virtual void reserved26();
    virtual void reserved27();
    virtual void reserved28();
    virtual void reserved29();
    virtual void reserved30();
    virtual void reserved31();
    virtual void reserved32();
    virtual void reserved33();
    virtual void reserved34();
    virtual void reserved35();
    virtual void reserved36();
    virtual void reserved37();
    virtual void reserved38();
    virtual void reserved39();
    virtual void reserved40();
    virtual unsigned int getButton();
};

struct WorkModule {
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void reserved3();
    virtual void reserved4();
    virtual void reserved5();
    virtual void reserved6();
    virtual void reserved7();
    virtual void reserved8();
    virtual void reserved9();
    virtual void reserved10();
    virtual void reserved11();
    virtual void reserved12();
    virtual void reserved13();
    virtual void reserved14();
    virtual void reserved15();
    virtual void reserved16();
    virtual void reserved17();
    virtual void onFlag(unsigned int);
    virtual void offFlag(unsigned int);
};

struct Modules {
    char pad0[0x5C];
    ControlModule* control;
    char pad1[4];
    WorkModule* work;
};

struct soModuleAccesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" unsigned int
getButtonMask__12soControllerFQ212soController9PadButton(int);

extern "C" float
getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

extern "C" void fn_120_E5CC(soModuleAccesser* accesser) {
    ControlModule* control = accesser->modules->control;
    unsigned int mask =
        getButtonMask__12soControllerFQ212soController9PadButton(1);
    unsigned int buttons = control->getButton();
    buttons &= mask;
    if (buttons) {
        accesser->modules->work->onFlag(0x22000012);
    } else {
        accesser->modules->work->offFlag(0x22000012);
    }

    control = accesser->modules->control;
    float limit =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xC42, 0);
    if (control->getStickY() >= limit) {
        accesser->modules->work->onFlag(0x22000012);
    }
}
