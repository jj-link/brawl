#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_27_135EE8(void*, int, soModuleAccesser*);

extern "C" void fn_93_9820(void* object, int situation, soModuleAccesser* accesser) {
    int status = accesser->getCollisionHitModule().getTotalStatus(0);
    fn_27_135EE8(object, situation, accesser);
    if (*(static_cast<unsigned char*>(object) + 0x1A348) == 1 &&
        accesser->getWorkManageModule().isFlag(0x12000035) == 1U) {
        if (status == 0) {
            accesser->getCollisionShieldModule().setStatus(0, 0, 1);
        } else {
            accesser->getCollisionShieldModule().setStatus(0, 1, 1);
        }
    }
}
