#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_95_12C50(void*, soModuleAccesser* accesser) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    soStatusModule* status = &accesser->getStatusModule();
    int kind = work->getInt(0x20000008);
    if (kind != -1) {
        status->changeStatusRequest(kind, accesser);
    }
}
