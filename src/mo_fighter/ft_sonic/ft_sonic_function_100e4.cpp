#pragma force_active on

struct WorkModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int getInt(unsigned long);
    virtual void setInt(int, unsigned long);
    virtual void v6();
    virtual void v7();
    virtual void decInt(unsigned long);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float getFloat(unsigned long);
    virtual void setFloat(float, unsigned long);
};

struct ControlModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual unsigned int getTrigger();
};

struct Modules {
    char pad[0x5c];
    ControlModule* control;
    char pad60[4];
    WorkModule* work;
};

struct soModuleAccesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
unsigned int getButtonMask__12soControllerFQ212soController9PadButton(int);
void fn_123_1025C(soModuleAccesser*);
void fn_123_10300(soModuleAccesser*);
}

extern "C" void fn_123_100E4(void*, soModuleAccesser* accesser) {
    float value = accesser->modules->work->getFloat(0x21000004);
    value -= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xfd9, 0);

    if (accesser->modules->work->getInt(0x20000003) > 0) {
        accesser->modules->work->decInt(0x20000003);
    } else {
        ControlModule* control = accesser->modules->control;
        if (control->getTrigger() &
            (getButtonMask__12soControllerFQ212soController9PadButton(1) |
             getButtonMask__12soControllerFQ212soController9PadButton(0))) {
            value += getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0xfdd, 0);
            WorkModule* work = accesser->modules->work;
            work->setInt(
                getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                    accesser, 0x5dca, 0),
                0x20000003);
        }
    }

    accesser->modules->work->setFloat(value, 0x21000004);
    fn_123_1025C(accesser);
    fn_123_10300(accesser);
}
