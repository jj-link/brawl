#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" {
void fn_117_22A84(void*, soModuleAccesser*);
extern const float lbl_117_rodata_128, lbl_117_rodata_12C;
}

extern "C" void fn_117_22354(void* self, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().getInt(0x20000004) == 2)
        return;
    soParamAccesser* params = static_cast<soParamAccesser*>(
        accesser->getWorkManageModule().getParamAccesser());
    switch (accesser->getStatusModule().getStatusKind()) {
    case 5: {
        if (accesser->getWorkManageModule().getInt(0x20000000) >=
            accesser->getWorkManageModule().getInt(0x20000001))
            fn_117_22A84(self, accesser);
        accesser->getWorkManageModule().addInt(1, 0x20000000);
        break;
    }
    case 17:
        if (accesser->getWorkManageModule().isFlag(0x2200000E)) {
            soWorkManageModule& work = accesser->getWorkManageModule();
            int limit = params->getParamInt(accesser, 0x5DC3, 0);
            if (work.getInt(0x20000009) < limit) {
                accesser->getWorkManageModule().subInt(1, 0x2000000A);
                if (accesser->getWorkManageModule().getInt(0x2000000A) <= 0) {
                    float count = accesser->getWorkManageModule().getInt(0x20000009);
                    float step = params->getParamFloat(accesser, 0xFA5, 0);
                    float extra = step * count;
                    float base = params->getParamFloat(accesser, 0xFA4, 0);
                    float value = base + extra;
                    accesser->getWorkManageModule().setFloat(value, 0x21000008);
                    accesser->getWorkManageModule().onFlag(0x2200000D);
                    accesser->getWorkManageModule().addInt(1, 0x20000009);
                    accesser->getWorkManageModule().setInt(
                        params->getParamInt(accesser, 0x5DC4, 0), 0x2000000A);
                }
            }
        }
        break;
    case 7:
        if (accesser->getWorkManageModule().getFloat(0x21000001) > lbl_117_rodata_128)
            accesser->getWorkManageModule().subFloat(lbl_117_rodata_12C, 0x21000001);
        break;
    }
    if (accesser->getWorkManageModule().getInt(0x10000004) > 0) {
        accesser->getWorkManageModule().subInt(1, 0x10000004);
        if (accesser->getWorkManageModule().getInt(0x10000004) == 0)
            accesser->getWorkManageModule().onFlag(0x22000004);
    }
}
