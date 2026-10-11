#include <so/so_module_accesser.h>

extern "C" {
extern const float lbl_98_rodata_E0, lbl_98_rodata_E8;
Vec3f* fn_98_F5B0(Vec3f*, float, float, float);
}

// Preserve an existing handle; otherwise request the follow effect and store it.
extern "C" void fn_98_1B904(soModuleAccesser* accesser, int handleIndex, unsigned int effectID) {
    soWorkManageModule& work = accesser->getWorkManageModule();
    soEffectModule& effect = accesser->getEffectModule();
    if (work.getInt(handleIndex) == 0) {
        Vec3f position;
        Vec3f rotation;
        unsigned int handle = effect.reqFollow(static_cast<EfID>(effectID), 0,
            fn_98_F5B0(&position, lbl_98_rodata_E8, lbl_98_rodata_E8, lbl_98_rodata_E8),
            fn_98_F5B0(&rotation, lbl_98_rodata_E8, lbl_98_rodata_E8, lbl_98_rodata_E8),
            lbl_98_rodata_E0, false, 0, 0, -1);
        work.setInt(handle, handleIndex);
    }
}

// Reacquire the effect module after the work callback before removing a handle.
extern "C" void fn_98_1B9EC(soModuleAccesser* accesser, int handleIndex) {
    soWorkManageModule& work = accesser->getWorkManageModule();
    int handle = work.getInt(handleIndex);
    if (handle != 0) accesser->getEffectModule().remove(handle);
    work.setInt(0, handleIndex);
}
