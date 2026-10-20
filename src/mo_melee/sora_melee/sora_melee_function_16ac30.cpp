#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_27_16AC30(void* unused, soModuleAccesser* acc) {
    acc->getCollisionShieldModule().setStatus(0, 0, 0);
    acc->getEffectModule().removeCommon(27);
}
