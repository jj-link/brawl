#include <so/so_module_accesser.h>

extern "C" bool fn_27_BE864(void*, void*, soModuleAccesser*, void*, void*, void*, void*);

extern "C" bool fn_117_11FC0(void* self, void* context, soModuleAccesser* accesser,
                              void* arg6, void* arg7, void* arg8, void* arg9) {
    if (accesser->getStatusModule().getStatusKind() != 0x96 &&
        accesser->getStatusModule().getStatusKind() != 0x97 &&
        !accesser->getItemManageModule().isHaveItem(0) &&
        accesser->getWorkManageModule().getInt(0x10000043) != -1) {
        accesser->getStatusModule().changeStatusForce(0x129, accesser);
        return true;
    }
    return fn_27_BE864(self, context, accesser, arg6, arg7, arg8, arg9);
}
