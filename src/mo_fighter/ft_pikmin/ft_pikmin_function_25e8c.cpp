#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_113_25E8C(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().getInt(0x10000011) & 0x40) {
        accesser->getGroundModule().setCorrect(soGroundShapeImpl::Correct_Ground_Cliff_Stop, 0);
    } else {
        accesser->getGroundModule().setCorrect(soGroundShapeImpl::Correct_Ground, 0);
    }
}
