#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_7B0C[];

int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);

void fn_27_3BE6C0(void*, void*, soModuleAccesser* accesser) {
    int status = accesser->getStatusModule().getStatusKind();
    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, status, accesser, 1)) {
    case 0x119:
    case 0x11A:
        accesser->getWorkManageModule().onFlag(0x22000012);
        break;
    }
}
}
