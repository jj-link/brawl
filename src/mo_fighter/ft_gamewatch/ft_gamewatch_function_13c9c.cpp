#include <so/so_module_accesser.h>
#include <so/motion/so_motion_module_impl.h>
#include <so/status/so_status_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" {
extern const float lbl_107_rodata_B0;
extern const float lbl_107_rodata_B4;

void fn_107_13C9C(void*, soModuleAccesser* acc) {
    soMotionModule& motion = acc->getMotionModule();
    if (acc->getStatusModule().getStatusKind() == 0x12b) {
        float workFloat = acc->getWorkManageModule().getFloat(0x11000000);
        float rate = lbl_107_rodata_B0;
        if (lbl_107_rodata_B4 != workFloat) {
            rate = motion.getEndFrame(0x201) / workFloat;
        }
        soMotionChangeParam param;
        param.m_kind = 0x201;
        param.m_frame = lbl_107_rodata_B4;
        param.m_rate = rate;
        param._12 = 0;
        param._13 = 0;
        param._14 = 0;
        param._15 = 0;
        motion.changeMotionRequest(&param);
    }
}
}
