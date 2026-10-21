#pragma force_active on

struct WorkModule {
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
    virtual float getFloat(unsigned int index);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual bool isFlag(unsigned int index);
};

struct SituationModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void setKeepAir(int keep);
};

struct Modules {
    char pad[0x58];
    SituationModule* situation;
    char pad5C[8];
    WorkModule* work;
};

struct FighterData {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_107_1FB58(void*, FighterData* fighter) {
    if (fighter->modules->work->isFlag(0x22000001)) {
        int value = (int)fighter->modules->work->getFloat(0x21000000);
        fighter->modules->situation->setKeepAir((value >> 1) & 1);
    }
}
