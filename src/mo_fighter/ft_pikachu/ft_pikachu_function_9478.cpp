#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_27_13138C(void*, int, int, soStatusData*, soModuleAccesser*);

extern "C" void fn_98_9478(void* fighter, int status, int previous,
                         soStatusData* data, soModuleAccesser* accesser) {
    fn_27_13138C(fighter, status, previous, data, accesser);
    if (previous == 0x2c) {
        accesser->getEffectModule().killAll(2, true, true);
    }
}
