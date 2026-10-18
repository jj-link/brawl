#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
extern "C" int randi__Fl(long);
extern "C" void fn_96_DC08(void* self);

extern "C" void fn_96_D874(void* self, soModuleAccesser* accesser) {
    if (!accesser->getWorkManageModule().isFlag(0x12000042)) {
        return;
    }
    if (accesser->getWorkManageModule().isFlag(0x12000043)) {
        return;
    }
    if (randi__Fl(getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0x5dc1, 0))) {
        return;
    }
    fn_96_DC08(self);
}
