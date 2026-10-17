#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" void fn_117_F410(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000011)) {
        accesser->getWorkManageModule().addInt(1, 0x20000001);
        soWorkManageModule& work = accesser->getWorkManageModule();
        int count = soValueAccesser::getConstantInt(accesser, 0x5dc4, 0);
        if (work.getInt(0x20000001) > count) {
            accesser->getWorkManageModule().offFlag(0x22000011);
            accesser->getWorkManageModule().onFlag(0x22000015);
        }
    }
}
