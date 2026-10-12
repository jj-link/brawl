#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

long randi(long);
extern "C" void fn_117_22E48(void*, soModuleAccesser*, int);

extern "C" void fn_117_22B20(void* self, soModuleAccesser* accesser) {
    int first, secondThreshold, third, fourth, fifth, second;
    soParamAccesser* params = static_cast<soParamAccesser*>(
        accesser->getWorkManageModule().getParamAccesser());
    first = params->getParamInt(accesser, 0x5DCB, 0);
    second = params->getParamInt(accesser, 0x5DC0, 0);
    third = params->getParamInt(accesser, 0x5DC1, 0);
    fourth = params->getParamInt(accesser, 0x5DCC, 0);
    fifth = params->getParamInt(accesser, 0x5DC2, 0);
    secondThreshold = first + second;
    third += secondThreshold;
    fourth += third;
    int random = randi(fifth + fourth);
    int kind;
    if (random < first) kind = 1;
    else if (random < secondThreshold) kind = 2;
    else if (random < third) kind = 3;
    else kind = random < fourth ? 4 : 5;
    accesser->getWorkManageModule().setInt(kind, 0x20000003);
    int durationRandom = randi(params->getParamInt(accesser, 0x5DC9, 0));
    int duration = params->getParamInt(accesser, 0x5DC8, 0);
    duration += durationRandom;
    fn_117_22E48(self, accesser, duration);
}
