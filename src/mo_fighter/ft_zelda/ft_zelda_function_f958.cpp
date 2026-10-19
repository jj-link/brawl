#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
void fn_104_F958(void*, soModuleAccesser* accesser) {
    accesser->getEffectModule().setSyncScale(true);
}
}
