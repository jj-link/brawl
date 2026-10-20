#pragma force_active on
struct Accesser;

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
    virtual float getFloat(int);
    virtual void setFloat(float, int);
};

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
    virtual void reserved18();
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
    virtual unsigned int getButtons();
};

struct StatusModule {
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void changeStatus(int, Accesser*);
};

struct Enumeration {
    char padding0[0x5C];
    ControlModule* control;
    char padding1[4];
    WorkModule* work;
    char padding2[8];
    StatusModule* status;
};

struct Accesser {
    char padding[0xD8];
    Enumeration* enumeration;
};

extern "C" unsigned int
getButtonMask__12soControllerFQ212soController9PadButton(int);

extern "C" float
getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, unsigned long, unsigned long);

extern "C" void fn_112_E00C(void*, Accesser*);

extern "C" void fn_112_DE84(void* self, Accesser* accesser) {
    float value = accesser->enumeration->work->getFloat(0x21000005);
    ControlModule* control = accesser->enumeration->control;
    unsigned int mask =
        getButtonMask__12soControllerFQ212soController9PadButton(1);
    unsigned int buttons = control->getButtons();
    buttons &= mask;
    if (buttons)
        value += getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xFA6, 0);

    value -= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xFA4, 0);

    if (value <= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                     accesser, 0xFA8, 0)) {
        accesser->enumeration->status->changeStatus(0x11C, accesser);
    } else {
        float maximum =
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0xFA5, 0);
        if (value > maximum)
            value = maximum;

        accesser->enumeration->work->setFloat(value, 0x21000005);
        float total = accesser->enumeration->work->getFloat(0x21000004);
        total += value;
        accesser->enumeration->work->setFloat(total, 0x21000004);
        fn_112_E00C(self, accesser);
    }
}
