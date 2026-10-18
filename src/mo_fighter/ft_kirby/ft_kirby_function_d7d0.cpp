#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_96_DC08(void*);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
extern "C" int randi__Fl(long);

extern "C" void fn_96_D7D0(void* self, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x12000042) &&
        !accesser->getWorkManageModule().isFlag(0x12000043)) {
        if (randi__Fl(getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0x5DC1, 0)) == 0) {
            fn_96_DC08(self);
        }
    }
}
