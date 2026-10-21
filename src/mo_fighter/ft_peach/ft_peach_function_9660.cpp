#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

struct PeachObj {
    char pad[0x60];
    soModuleAccesser* accesser;
};

extern "C" bool fn_27_135EE0(void*);

extern "C" bool fn_103_9660(PeachObj* self) {
    if (self->accesser->getStatusModule().getStatusKind() == 0x117) {
        if (self->accesser->getWorkManageModule().isFlag(0x22000011) == 1U) {
            self->accesser->getStatusModule().changeStatusRequest(0x118, self->accesser);
            return true;
        }
    }
    return fn_27_135EE0(self);
}
