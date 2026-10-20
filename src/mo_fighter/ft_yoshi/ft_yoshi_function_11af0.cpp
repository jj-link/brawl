#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_95_11AF0(void*, soModuleAccesser* accesser) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    soStatusModule* status = &accesser->getStatusModule();
    int nextStatus = work->getInt(0x20000008);
    if (nextStatus != -1) {
        status->changeStatusRequest(nextStatus, accesser);
    }
}
