#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_109_D698(void*, soModuleAccesser* accesser) {
    if (accesser->getSituationModule().getKind() == 0) {
        accesser->getKineticModule().clearSpeedAll();
    }
}
