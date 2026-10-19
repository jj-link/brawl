#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" float lbl_95_rodata_58;

extern "C" void fn_95_FA74(void*, soModuleAccesser* accesser) {
    Vec3f rotation(lbl_95_rodata_58, lbl_95_rodata_58, lbl_95_rodata_58);
    accesser->getPostureModule().setRot(&rotation, 0);
}
