#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/motion/so_motion_module_impl.h>
#pragma force_active on
#pragma fp_contract off

extern "C" void fn_27_168AA8(void*, soModuleAccesser* accesser) {
    float frames = (float)soValueAccesser::getConstantInt(accesser, 0x59DA, 0);
    float rate = accesser->m_enumerationStart->m_motionModule->getEndFrame(0x14) / frames;
    if (rate < 1.0f) {
        rate += 0.001f;
    }
    soMotionChangeParam param;
    param.m_kind = 0x14;
    param.m_frame = 0.0f;
    param.m_rate = rate;
    param._12 = 0;
    param._13 = 0;
    param._14 = 0;
    param._15 = 0;
    accesser->m_enumerationStart->m_motionModule->changeMotionRequest(&param);
}
