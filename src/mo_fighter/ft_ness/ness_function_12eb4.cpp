#include <so/so_module_accesser.h>
#include <so/collision/so_collision_shield_module_impl.h>
#include <so/effect/so_effect_module_impl.h>
#include <so/sound/so_sound_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>

extern "C" {
Vec3f* fn_101_1303C(Vec3f*, float, float, float);
}

// Enable absorption and create the persistent effect and sound only once.
extern "C" void fn_101_12EB4(void*, soModuleAccesser* accesser) {
    accesser->getCollisionAbsorberModule().setStatus(0, 1, 0);
    if (accesser->getWorkManageModule().getInt(0x20000003) < 0) {
        soEffectModule& effect = accesser->getEffectModule();
        Vec3f position, rotation;
        int handle = effect.reqFollow(static_cast<EfID>(0xB000C), 4,
            fn_101_1303C(&position, 0.0f, 6.5f, 0.0f),
            fn_101_1303C(&rotation, 0.0f, 0.0f, 0.0f),
            0.9f, false, 0, 0, -1);
        accesser->getWorkManageModule().setInt(handle, 0x20000003);
    }
    if (accesser->getWorkManageModule().getInt(0x20000002) < 0) {
        int handle = accesser->getSoundModule().playSE(static_cast<SndID>(0xE7F), true, 0, 0);
        accesser->getWorkManageModule().setInt(handle, 0x20000002);
    }
}
