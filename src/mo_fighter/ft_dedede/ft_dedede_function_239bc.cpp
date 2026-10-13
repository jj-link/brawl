#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mt/mt_prng.h>

extern "C" void fn_117_239BC(void*, soModuleAccesser* accesser) {
    soParamAccesser* params = static_cast<soParamAccesser*>(
        accesser->getWorkManageModule().getParamAccesser());
    if (accesser->getWorkManageModule().isFlag(0x22000006)) {
        float chance = params->getParamFloat(accesser, 0xFB9, 0);
        if (randf() < chance)
            accesser->getWorkManageModule().setInt(4, 0x20000003);
        accesser->getWorkManageModule().offFlag(0x22000006);
    }
}
