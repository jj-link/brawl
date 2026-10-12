#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

struct PikachuGravityState {
    char prefix[0xc];
    float speed;
    float acceleration;
    float stableSpeed;
    float brake;
    float limitSpeed;
};

extern "C" {
extern const char lbl_98_data_769C[], lbl_98_data_24B0[];
extern const float lbl_98_rodata_80;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_98_9890(soModuleAccesser*);
void fn_98_1856C(void*, float);
}

#pragma always_inline on
#pragma inline_depth(8)
extern "C" void fn_98_11190(void*, soModuleAccesser* accesser) {
    const soModuleEnumeration& modules = *accesser->m_enumerationStart;
    soWorkManageModule& work = *modules.m_workManageModule;
    soKineticModule& kinetic = *modules.m_kineticModule;
    void* owner = fn_98_9890(accesser);
    int previousSituation = work.getInt(0x20000002);
    int situation = accesser->getSituationModule().getKind();
    if (situation != previousSituation) {
        work.setInt(situation, 0x20000002);
        if (situation == 0) {
            kinetic.changeKinetic(6, accesser);
        } else {
            kinetic.changeKinetic(10, accesser);
            PikachuGravityState* gravity = static_cast<PikachuGravityState*>(__dynamic_cast(
                kinetic.getEnergy(1), 0, lbl_98_data_769C, lbl_98_data_24B0, 1));
            float speed = soValueAccesser::getConstantFloat(accesser, 0xfc8, 0);
            float acceleration = soValueAccesser::getConstantFloat(accesser, 0xfc9, 0);
            gravity->speed = speed;
            gravity->acceleration = -acceleration;
            gravity->stableSpeed = speed;
            gravity->limitSpeed = speed;
            gravity->brake = lbl_98_rodata_80;
        }
    }
    if (owner) {
        Vec3f position = accesser->getModelModule().getNodeGlobalPosition(0x18, true);
        fn_98_1856C(owner, position.m_y);
    }
}
