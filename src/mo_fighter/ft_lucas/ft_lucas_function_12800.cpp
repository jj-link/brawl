#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct LucasEnergy : soKineticEnergy {
    Vec2f speed;

    void setSpeed(const Vec2f& value) {
        speed.m_x = value.m_x;
        speed.m_y = value.m_y;
    }
};

struct LucasParams {
    char pad[0xc];
    float speedMul;
};

struct LucasParamAccess {
    char pad[0xc];
    LucasParams* params;
};

struct LucasFighter {
    char pad0[8];
    void* param;
    char pad1[0xcc];
    const soModuleEnumeration* modules;
};

extern "C" LucasParamAccess* fn_114_AE9C(void*);
extern "C" char lbl_114_data_8040[];
extern "C" char lbl_114_data_31DC[];
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);

extern "C" void fn_114_12800(void*, LucasFighter* fighter) {
    if (fighter->modules->m_situationModule->getKind() == 2) {
        soKineticModule* kinetic = fighter->modules->m_kineticModule;
        LucasParams* params = fn_114_AE9C(fighter->param)->params;
        LucasEnergy* energy = (LucasEnergy*)__dynamic_cast(
            kinetic->getEnergy(3), 0,
            lbl_114_data_8040, lbl_114_data_31DC, 1);

        Vec2f speed;
        Vec2f::copy(speed, energy->getSpeed());
        speed.m_x *= params->speedMul;
        energy->setSpeed(speed);

        kinetic->getEnergy(1)->clearSpeed();
        kinetic->getEnergy(0)->clearSpeed();
    }

    fighter->modules->m_workManageModule->setInt(-1, 0x20000002);
    fighter->modules->m_workManageModule->setInt(-1, 0x20000003);
}
