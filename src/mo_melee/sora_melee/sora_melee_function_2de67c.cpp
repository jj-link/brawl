class soCollisionAttackModule;

#include <so/work/so_work_manage_module_impl.h>
#include <so/damage/so_damage_module_impl.h>
#pragma force_active on

struct Modules {
    char unused0[0x38];
    soDamageModule* damage;
    char unused1[0x28];
    soWorkManageModule* work;
};

struct Object {
    char unused[0xD8];
    Modules* modules;
};

extern "C" const float lbl_27_rodata_63A0[];

extern "C" void fn_27_2DE67C(void*, Object* object) {
    object->modules->work->setInt(0, 0x10000040);
    object->modules->damage->setNoReactionModeStatus(
        lbl_27_rodata_63A0[0], lbl_27_rodata_63A0[0], 0);
}
