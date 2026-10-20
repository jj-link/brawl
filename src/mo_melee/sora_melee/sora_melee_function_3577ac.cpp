#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_27_3577AC(void* self, soModuleAccesser* accesser) {
    for (s32 i = 3; i < 7; i++) {
        if (accesser->getItemManageModule().isHaveItem(i)) {
            accesser->getItemManageModule().removeItem(i);
        }
    }
}
