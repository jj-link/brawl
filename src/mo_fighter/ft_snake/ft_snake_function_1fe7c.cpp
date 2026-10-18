#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

struct SnakeObj {
    char _pad[0x60];
    soModuleAccesser* m_accesser;
};

extern "C" bool fn_122_1FE7C(SnakeObj* self) {
    if (self->m_accesser->getStatusModule().getStatusKind() == 1) {
        if (self->m_accesser->getWorkManageModule().isFlag(0x22000000)) {
            self->m_accesser->getStatusModule().changeStatusRequest(3, self->m_accesser);
            return true;
        }
    }
    return false;
}
