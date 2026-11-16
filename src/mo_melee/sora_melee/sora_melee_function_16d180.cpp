#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" int fn_27_19585C(soModuleAccesser*);

extern "C" void fn_27_16D180(soModuleAccesser*, soModuleAccesser* self) {
    if ((unsigned int)fn_27_19585C(self) == 1) {
        int val = self->m_enumerationStart->m_workManageModule->getInt(0x10000038);
        float f = (float)val * soValueAccesser::getConstantFloat(self, 0xCDC, 0);
        self->m_enumerationStart->m_workManageModule->setInt((int)f, 0x10000038);
    }
}

extern "C" const double lbl_27_rodata_21B8 = 727846615040.0;
