#include <so/so_module_accesser.h>

struct QuickAttackGravityEnergy {
    void* vtable;
    unsigned char nullable;
    unsigned char enabled : 1;
    unsigned char : 7;
    unsigned char suspended;
    unsigned char padding;
    float horizontalSpeed;
    float verticalSpeed;
    float acceleration;
};
struct QuickAttackGravityParameters {
    char prefix[8];
    float acceleration;
};
struct QuickAttackGravityParameterView {
    char prefix[8];
    QuickAttackGravityParameters* parameters;
};
extern "C" {
extern const char lbl_98_data_600[], lbl_98_data_2F88[];
extern const char lbl_98_data_769C[], lbl_98_data_24B0[];
extern const float lbl_98_rodata_20;
void* __dynamic_cast(void*, long, const void*, const void*, short);
QuickAttackGravityParameterView* fn_98_9530(void*);
}

// Resume gravity after the airborne Quick Attack delay expires.
extern "C" void fn_98_EA24(void*, soModuleAccesser* accesser) {
    void* fighter = __dynamic_cast(accesser->m_stageObject, 0x3c,
        lbl_98_data_600, lbl_98_data_2F88, 1);
    soWorkManageModule& work = accesser->getWorkManageModule();
    int delay = work.getInt(0x20000002);
    work.setInt(delay - 1, 0x20000002);
    if (accesser->getSituationModule().getKind() != 0) {
        QuickAttackGravityEnergy* gravity = static_cast<QuickAttackGravityEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(1), 0,
            lbl_98_data_769C, lbl_98_data_24B0, 1));
        if (delay - 1 >= 0) {
            gravity->enabled = 0;
            gravity->verticalSpeed = lbl_98_rodata_20;
        } else {
            QuickAttackGravityParameters* parameters = fn_98_9530(fighter)->parameters;
            gravity->enabled = 1;
            gravity->acceleration = parameters->acceleration;
        }
    }
}
