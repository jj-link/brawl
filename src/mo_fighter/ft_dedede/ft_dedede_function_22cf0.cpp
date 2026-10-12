#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

long randi(long);
extern "C" void fn_117_22E48(void*, soModuleAccesser*, int);

extern "C" void fn_117_22CF0(void* self, soModuleAccesser* accesser) {
    soParamAccesser* params = static_cast<soParamAccesser*>(
        accesser->getWorkManageModule().getParamAccesser());
    int first = params->getParamInt(accesser, 0x5DCB, 0);
    int second = params->getParamInt(accesser, 0x5DCC, 0);
    int third = params->getParamInt(accesser, 0x5DC5, 0);
    int secondThreshold = first + second;
    int random = randi(third + secondThreshold);
    int kind;
    if (random < first) kind = 1;
    else if (random < secondThreshold) kind = 4;
    else kind = 6;
    accesser->getWorkManageModule().setInt(kind, 0x20000003);
    int durationRandom = randi(params->getParamInt(accesser, 0x5DC9, 0));
    int duration = params->getParamInt(accesser, 0x5DC8, 0);
    duration += durationRandom;
    fn_117_22E48(self, accesser, duration);
}
