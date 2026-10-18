#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

extern "C" void fn_120_104D0(void* unused, soModuleAccesser* accesser, int eventKind) {
    switch (eventKind) {
        case 0:
        case 0xE:
            accesser->getWorkManageModule().onFlag(0x12000043);
            accesser->getWorkManageModule().setInt(getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0x5dc9, 0) * 0x3c, 0x10000042);
            break;
    }
}
