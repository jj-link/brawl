#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_95_138BC(void* unk, soModuleAccesser* accesser) {
    accesser->getSituationModule().setKeepAir(true);
}
