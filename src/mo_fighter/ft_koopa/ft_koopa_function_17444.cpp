#pragma force_active on

struct Flags {
    unsigned char pad[5];
    unsigned char f7 : 1;
    unsigned char rest : 7;
};

class Kinetic {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual unsigned char* getEnergy(int);
};

struct Modules {
    char pad0[0x7C];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_102_17444(Accesser* accesser) {
    Flags* p;
    p = (Flags*)accesser->modules->kinetic->getEnergy(0);
    p->f7 = 0;
    p = (Flags*)accesser->modules->kinetic->getEnergy(1);
    p->f7 = 0;
    p = (Flags*)accesser->modules->kinetic->getEnergy(2);
    p->f7 = 0;
    p = (Flags*)accesser->modules->kinetic->getEnergy(3);
    p->f7 = 0;
}
