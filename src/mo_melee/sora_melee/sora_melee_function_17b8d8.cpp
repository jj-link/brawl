#pragma force_active on

struct ControlModule {
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual void r30();
    virtual void r31();
    virtual void r32();
    virtual void r33();
    virtual void r34();
    virtual void r35();
    virtual void r36();
    virtual void r37();
    virtual unsigned int fn38();
    virtual void r39();
    virtual void r40();
    virtual void r41();
    virtual unsigned int fn42();
};

struct WorkModule {
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual int getInt(unsigned int);
    virtual void setInt(int, unsigned int, void*);
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void onFlag(unsigned int, void*);
};

struct Modules {
    char pad[0x5c];
    ControlModule* control;
    char pad2[4];
    WorkModule* work;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" unsigned int
getButtonMask__12soControllerFQ212soController9PadButton(int);

extern "C" int
getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, unsigned long, unsigned long);

extern "C" void fn_27_17E908(Accesser*);

extern "C" void fn_27_17B8D8(void*, Accesser* self) {
    switch (self->modules->work->getInt(0x2000000C)) {
    case 0: {
        ControlModule* control = self->modules->control;
        unsigned int mask =
            getButtonMask__12soControllerFQ212soController9PadButton(0);
        unsigned int buttons = control->fn42();
        if (buttons & mask) {
            self->modules->work->onFlag(0x22000013, self->modules);
        }
        break;
    }
    case 1: {
        ControlModule* control = self->modules->control;
        unsigned int mask =
            getButtonMask__12soControllerFQ212soController9PadButton(0);
        unsigned int buttons = control->fn38();
        if (buttons & mask) {
            self->modules->work->setInt(
                getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                    self, 0x5a60, 0),
                0x2000000D, self->modules);
        }
        break;
    }
    }
    fn_27_17E908(self);
}
