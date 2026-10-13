#include <so/so_module_accesser.h>

extern "C" void fn_117_23788(void*, soModuleAccesser* accesser, int statusKind) {
    if (accesser->getStatusModule().getStatusKind() != 20)
        accesser->getWorkManageModule().offFlag(0x22000007);
    if (accesser->getStatusModule().getStatusKind() != 22)
        accesser->getWorkManageModule().offFlag(0x22000008);
    accesser->getWorkManageModule().offFlag(0x22000009);
    if (statusKind != 21)
        accesser->getWorkManageModule().offFlag(0x2200000B);
}
