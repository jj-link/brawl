#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_186F0C(void* self, soModuleAccesser* accesser) {
    if (soValueAccesser::getConstantInt(accesser, 0x5A98, 0) == 1) {
        accesser->getMotionModule().setKindOffset(4);
    }
}
}
