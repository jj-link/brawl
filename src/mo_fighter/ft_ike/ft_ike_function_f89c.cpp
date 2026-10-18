#include <so/so_module_accesser.h>
#pragma force_active on

extern const float lbl_119_rodata_6C;

extern "C" void fn_119_F89C(void* unk, soModuleAccesser* accesser) {
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x122:
        if (accesser->getWorkManageModule().isFlag(0x22000012)) {
            if (accesser->getWorkManageModule().getFloat(0x21000008) <= lbl_119_rodata_6C) {
                accesser->getStatusModule().changeStatusRequest(0x123, accesser);
            }
        }
        break;
    case 0x123:
        if (accesser->getWorkManageModule().isFlag(0x22000013)) {
            accesser->getStatusModule().changeStatusRequest(0x124, accesser);
        }
        break;
    }
}
