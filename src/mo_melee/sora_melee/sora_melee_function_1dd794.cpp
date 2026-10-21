#pragma force_active on

struct Module;

struct PhysicsBase {
    char pad[8];
};

struct Physics : PhysicsBase {
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
    virtual int getCount();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual int getState();
};

struct Work {
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
    virtual int getFlag(unsigned long);
};

struct Status {
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
    virtual void changeStatus(int, Module*);
};

struct Enumeration {
    char pad0[0x64];
    Work* work;
    char pad1[8];
    Status* status;
    char pad2[0x28];
    Physics* physics;
};

struct Module {
    char pad[0xD8];
    Enumeration* modules;
};

extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    Module*, unsigned long, unsigned long);

extern "C" void fn_27_1DD794(void*, Module* module) {
    if (module->modules->physics->getState() == 2) {
        module->modules->status->changeStatus(2, module);
        return;
    }

    int count;
    if (module->modules->work->getFlag(0x22000000) == 0) {
        count = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
            module, 0x5DC1, 0);
    } else {
        count = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
            module, 0x5DC0, 0);
    }

    if (module->modules->physics->getCount() >= count) {
        module->modules->status->changeStatus(2, module);
    }
}
