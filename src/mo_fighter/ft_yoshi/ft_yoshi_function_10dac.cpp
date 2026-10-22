#include <ft/ft_common_data_accesser.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_95_data_810C[];
extern const unsigned char lbl_95_data_2C38[];
extern const unsigned char lbl_95_data_7A88[];
extern const float lbl_95_rodata_88;
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct Energy {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    char pad04[0xC];
    float f10;
    float f14;
    char pad18[4];
    float f1C;
};

struct KineticModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getEnergy(int);
};

struct Situation {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int getKind();
};

struct WorkModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setInt(int, int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void setFloat(float, int);
};

struct Modules {
    char pad00[0x14];
    Situation* situation;
    char pad18[0x4C];
    WorkModule* work;
    char pad68[0x14];
    KineticModule* kinetic;
};

struct Accesser {
    char pad00[0xD8];
    Modules* modules;
};

extern "C" void fn_95_10DAC(void*, Accesser* accesser) {
    Modules* modules = accesser->modules;
    WorkModule* work = modules->work;
    Situation* situation = modules->situation;
    KineticModule* kinetic = modules->kinetic;
    ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(4));
    unsigned char* params =
        *reinterpret_cast<unsigned char**>(reinterpret_cast<unsigned char*>(data) + 0x7C);

    Energy* e1 = static_cast<Energy*>(__dynamic_cast(
        kinetic->getEnergy(1), 0, lbl_95_data_810C, lbl_95_data_2C38, 1));
    Energy* e3 = static_cast<Energy*>(__dynamic_cast(
        kinetic->getEnergy(3), 0, lbl_95_data_7A88, lbl_95_data_2C38, 1));

    if (situation->getKind() == 2) {
        Energy* e = static_cast<Energy*>(__dynamic_cast(
            kinetic->getEnergy(1), 0, lbl_95_data_810C, lbl_95_data_2C38, 1));
        e->f10 = -*reinterpret_cast<float*>(params + 0x24);
        e->f1C = *reinterpret_cast<float*>(params + 0x28);
        e->f14 = *reinterpret_cast<float*>(params + 0x28);
        work->setFloat(lbl_95_rodata_88, 0x21000008);
        return;
    }

    e1->v6();
    e3->v6();
    work->setFloat(lbl_95_rodata_88, 0x21000008);
    work->setInt(0, 0x20000006);
}
