#include <wn/weapon.h>
#pragma force_active on

extern "C" {
void fn_98_10474(void*, soModuleAccesser* moduleAccesser) {
    soWorkManageModule* work = &moduleAccesser->getWorkManageModule();
    work->getInt(0x20000000);
    if (work->isFlag(0x22000010)) {
        work->setInt(work->getInt(0x20000000), 0x20000000);
    }
}
}
