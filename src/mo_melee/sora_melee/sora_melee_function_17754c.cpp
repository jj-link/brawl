#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_2308;
extern "C" const float lbl_27_rodata_230C;
extern "C" void fn_27_176C68(void*, soModuleAccesser*, float, int);

extern "C" void fn_27_17754C(void* arg1, soModuleAccesser* accesser, float* arg3) {
    fn_27_176C68(arg1, accesser, arg3[2], 0);

    if (lbl_27_rodata_2308 == accesser->m_enumerationStart->m_postureModule->getLr()) {
        Vec3f rot = accesser->m_enumerationStart->m_postureModule->getRot(0);
        rot.m_y = lbl_27_rodata_230C;
        accesser->m_enumerationStart->m_postureModule->setRot(&rot, 0);
    }

    accesser->m_stageObject->updateNodeSRT();
}
