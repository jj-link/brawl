#include <so/so_module_accesser.h>

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

#pragma force_active on
extern "C" void fn_93_10F64(void* self, soModuleAccesser* accesser) {
    Vec3f nodeScale;
    nodeScale.m_x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xfb1, 0);
    nodeScale.m_y = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xfb2, 0);
    nodeScale.m_z = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xfb3, 0);
    accesser->getModelModule().setNodeScale(0xfd, &nodeScale);
}
