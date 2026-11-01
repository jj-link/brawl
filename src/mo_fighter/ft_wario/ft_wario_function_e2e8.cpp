#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <so/situation/so_situation_module_impl.h>
#include <mt/mt_vector.h>

#pragma force_active on

extern "C" {
extern const unsigned char lbl_110_data_5F8[];
extern const unsigned char lbl_110_data_62B8[];
extern const unsigned char lbl_110_data_212C[];
extern const unsigned char lbl_110_data_6098[];
extern const unsigned char lbl_110_data_617C[];
extern const unsigned char lbl_110_data_168C[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_110_8C60(void*);
void* fn_110_1EF78(void*);
}

struct FighterPrefix {
    unsigned char pad0[0x3c];
};

struct FighterView : FighterPrefix {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual int kind();
};

struct ModuleView {
    unsigned char pad0[0x14];
    soSituationModule* situation;
    unsigned char pad18[0x64];
    soKineticModule* kinetic;
};

struct AccessView {
    unsigned char pad0[8];
    FighterView* fighter;
    unsigned char pad0c[0xcc];
    ModuleView* modules;
};

struct EnergyFields {
    unsigned char pad0[8];
    float x;
    float y;
    float z;
};

extern "C" void fn_110_E2E8(void*, AccessView* accesser) {
    ModuleView* modules = accesser->modules;
    soKineticModule* kinetic = modules->kinetic;
    soSituationModule* situation = modules->situation;
    FighterView* fighter = accesser->fighter;

    int kind = fighter->kind();

    float* params;
    if (kind == 0x15) {
        void* casted = __dynamic_cast(
            fighter, 0x3c, lbl_110_data_5F8, lbl_110_data_212C, 1);
        params = *reinterpret_cast<float**>(
            reinterpret_cast<unsigned char*>(fn_110_8C60(casted)) + 8);
    } else {
        void* casted = __dynamic_cast(
            fighter, 0x3c, lbl_110_data_62B8, lbl_110_data_212C, 1);
        params = *reinterpret_cast<float**>(
            reinterpret_cast<unsigned char*>(fn_110_1EF78(casted)) + 8);
    }

    if (situation->getKind() == 0) {
        kinetic->changeKinetic(6, reinterpret_cast<soModuleAccesser*>(accesser));
    } else {
        kinetic->changeKinetic(0xA, reinterpret_cast<soModuleAccesser*>(accesser));
    }

    void* energy0 = __dynamic_cast(
        kinetic->getEnergy(3), 0, lbl_110_data_6098, lbl_110_data_168C, 1);
    void* energy1 = __dynamic_cast(
        kinetic->getEnergy(1), 0, lbl_110_data_617C, lbl_110_data_168C, 1);

    Vec2f speed;
    speed = reinterpret_cast<soKineticEnergy*>(energy0)->getSpeed();
    EnergyFields* fields0 = reinterpret_cast<EnergyFields*>(energy0);
    speed.m_x *= params[0];
    fields0->x = speed.m_x;
    fields0->y = speed.m_y;

    speed = reinterpret_cast<soKineticEnergy*>(energy1)->getSpeed();
    EnergyFields* fields1 = reinterpret_cast<EnergyFields*>(energy1);
    speed.m_y += params[1];
    fields1->y = speed.m_y;
    fields1->z = params[2];
}
