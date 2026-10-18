#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern float lbl_115_rodata_60;
void fn_115_F0A8(void*);
}

extern "C" void fn_115_F338(void* p1, soModuleAccesser* accesser) {
    accesser->getWorkManageModule().setInt(-1, 0x20000001);
    accesser->getWorkManageModule().setFloat(lbl_115_rodata_60, 0x21000004);
    if (accesser->getSituationModule().getKind() != 0) {
        fn_115_F0A8(accesser);
    }
}
