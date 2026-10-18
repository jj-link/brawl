#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
void* fn_98_9890(soModuleAccesser* accesser);
bool fn_98_17DEC(void* owner, const Vec3f* point);

void fn_98_11064(void*, soModuleAccesser* accesser) {
    void* owner = fn_98_9890(accesser);
    if (owner) {
        Vec3f pos = accesser->getModelModule().getNodeGlobalPosition(0x18, true);
        if (fn_98_17DEC(owner, &pos)) {
            accesser->getStatusModule().changeStatusRequest(0x11d, accesser);
        }
    }
}
}
