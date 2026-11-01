#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/controller/so_controller_module_impl.h>
#include <types.h>

#pragma force_active on

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, u32, u32);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, u32, u32);

extern "C" const float lbl_27_rodata_2058;
extern "C" const float lbl_27_rodata_205C;

extern "C" void fn_27_1669DC(void*, soModuleAccesser* self) {
    self->m_enumerationStart->m_workManageModule->offFlag(0x22000011);

    if (self->m_enumerationStart->m_workManageModule->getFloat(0x21000005) >
        lbl_27_rodata_2058) {
        self->m_enumerationStart->m_workManageModule->subFloat(
            lbl_27_rodata_205C, 0x21000005);
    } else if (!self->m_enumerationStart->m_workManageModule->isFlag(
                   0x22000012)) {
        self->m_enumerationStart->m_workManageModule->onFlag(0x22000012);
        self->m_enumerationStart->m_workManageModule->onFlag(0x22000011);
    }

    float limit =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            self, 0xC32, 0);
    int flickLimit = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
        self, 0x59F7, 0);

    soControllerModule* controller =
        self->m_enumerationStart->m_controllerModule;

    if (controller->getStickX() *
            (-self->m_enumerationStart->m_workManageModule->getFloat(
                0x21000004)) >=
        limit) {
        if (self->m_enumerationStart->m_controllerModule->getFlickX() <
            flickLimit) {
            self->m_enumerationStart->m_workManageModule->onFlag(0x22000010);
        }
    }
}
