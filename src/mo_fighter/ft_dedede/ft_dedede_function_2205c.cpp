#pragma section data_type ".data$dedede2205C" ".bss"

#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

long randi(long);
extern "C" {
void fn_117_22E48(void*, soModuleAccesser*, int);
extern const float lbl_117_rodata_128;
}

extern "C" void fn_117_2205C(void* self, soModuleAccesser* accesser) {
    soParamAccesser* params = static_cast<soParamAccesser*>(
        accesser->getWorkManageModule().getParamAccesser());
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0:
        accesser->getWorkManageModule().setFloat(lbl_117_rodata_128, 0x21000004);
    case 1: {
        int random = randi(params->getParamInt(accesser, 0x5DC9, 0));
        int duration = params->getParamInt(accesser, 0x5DC8, 0);
        duration += random;
        fn_117_22E48(self, accesser, duration);
        break;
    }
    case 6:
        accesser->getPostureModule().reverseLr();
        break;
    case 11:
    case 14:
        accesser->getWorkManageModule().offFlag(0x22000003);
        break;
    case 17:
        accesser->getWorkManageModule().setInt(0, 0x20000009);
        accesser->getWorkManageModule().offFlag(0x2200000E);
        accesser->getWorkManageModule().setFloat(
            params->getParamFloat(accesser, 0xFA6, 0), 0x21000009);
        accesser->getWorkManageModule().setFloat(
            params->getParamFloat(accesser, 0xFA7, 0), 0x2100000A);
        break;
    case 7:
        if (!accesser->getWorkManageModule().isFlag(0x22000004)) {
            float increment = accesser->getWorkManageModule().getFloat(0x21000000);
            accesser->getWorkManageModule().addFloat(increment, 0x21000004);
            if (accesser->getWorkManageModule().getFloat(0x21000004) >=
                params->getParamFloat(accesser, 0xFAB, 0))
                accesser->getWorkManageModule().onFlag(0x22000004);
        }
        break;
    }
}
