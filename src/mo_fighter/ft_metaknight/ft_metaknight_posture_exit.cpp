#include <so/so_module_accesser.h>

#include <ft_metaknight/ft_metaknight_posture_constants.h>

extern "C" void fn_111_C820(void*, soModuleAccesser* accesser, int status) {
    if (status != 0x11A) {
        Vec3f rotation(lbl_111_rodata_10.neutral, lbl_111_rodata_10.neutral, lbl_111_rodata_10.neutral);
        accesser->getPostureModule().setRot(&rotation, 0);
        accesser->getPostureModule().updateRotYLr();
    } else if (accesser->getGroundModule().attachGround(0) == true) {
        accesser->getSituationModule().setKind(Situation_Ground, false);
    }
}
