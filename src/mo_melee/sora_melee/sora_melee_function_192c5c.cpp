#include <so/so_module_accesser.h>
#include <so/motion/so_motion_module_impl.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#pragma force_active on

extern "C" void fn_27_192C5C(void* arg0, soModuleAccesser* moduleAccesser) {
    soMotionModule* motionModule = moduleAccesser->m_enumerationStart->m_motionModule;
    if (motionModule->is2ndEnd()) {
        moduleAccesser->m_enumerationStart->m_kineticModule->changeKinetic(0x13, moduleAccesser);
        motionModule->remove2ndAnimChr();
    }
}
