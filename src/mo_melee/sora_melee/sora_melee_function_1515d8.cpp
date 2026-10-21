#pragma force_active on

struct soModuleAccesser;

struct Ground {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual int enabled();
};

struct Work {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual int get(unsigned long);
};

struct Reaction {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void set(int, soModuleAccesser*);
};

struct Modules {
    char pad0[0x14];
    Ground* ground;
    char pad1[0x48];
    Reaction* reaction;
    Work* work;
};

struct soModuleAccesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

extern "C" void fn_27_1515D8(
    void*, soModuleAccesser* accesser, int kind, float value)
{
    if (kind == 3) {
        if (accesser->modules->ground->enabled() != 0) {
            int level;
            if (value >= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                             accesser, 0x7F4, 0)) {
                level = 2;
            } else {
                level = value >=
                    getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                        accesser, 0x7F3, 0);
            }

            if (level == 2) {
                if (accesser->modules->work->get(0x1000002C) > 8) {
                    level = 1;
                }
            }

            accesser->modules->reaction->set(level, accesser);
        }
    }
}
