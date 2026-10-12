#include <so/so_module_accesser.h>

extern "C" {
extern const float lbl_117_rodata_140;
extern const float lbl_117_rodata_144;
void fn_117_23880(void*, soModuleAccesser*);
void fn_117_239BC(void*, soModuleAccesser*);
}

extern "C" void fn_117_2322C(void* process, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().getInt(0x20000004) != 2) {
        fn_117_23880(process, accesser);
        switch (accesser->getStatusModule().getStatusKind()) {
        case 18:
        case 19:
        case 22:
            fn_117_239BC(process, accesser);
            break;
        case 23:
            if (accesser->getWorkManageModule().getFloat(0x21000001) > lbl_117_rodata_140)
                accesser->getWorkManageModule().subFloat(lbl_117_rodata_144, 0x21000001);
            break;
        }
    }
    if (accesser->getWorkManageModule().getInt(0x10000004) > 0) {
        accesser->getWorkManageModule().subInt(1, 0x10000004);
        if (accesser->getWorkManageModule().getInt(0x10000004) == 0)
            accesser->getWorkManageModule().onFlag(0x22000004);
    }
}
