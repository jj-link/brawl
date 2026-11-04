#include <so/so_value_accesser.h>
#pragma force_active on
#pragma fp_contract off

extern const float lbl_27_rodata_20E0;
extern const float lbl_27_rodata_20E4;

extern "C" void fn_27_169A04(void*, soModuleAccesser* obj) {
    int status = obj->m_enumerationStart->m_statusModule->getStatusKind();
    if (status == 22) {
        float rate = lbl_27_rodata_20E0;
        float duration = obj->m_enumerationStart->m_workManageModule->getFloat(0x11000000);
        if (lbl_27_rodata_20E4 != duration)
            rate = obj->m_enumerationStart->m_motionModule->getEndFrame(0x32) / duration;
        soMotionChangeParam param;
        param.m_kind = 0x32;
        param.m_frame = lbl_27_rodata_20E4;
        param.m_rate = rate;
        param._12 = 0;
        param._13 = 0;
        param._14 = 0;
        param._15 = 0;
        obj->m_enumerationStart->m_motionModule->changeMotionRequest(&param);
    } else if (status == 23) {
    } else if (status == 24) {
        int index = obj->m_enumerationStart->m_workManageModule->getInt(0x20000000);
        float rate = lbl_27_rodata_20E0;
        int kind = index + 5;
        float duration = soValueAccesser::getConstantFloat(obj, index + 0xba1, 0);
        if (lbl_27_rodata_20E4 != duration) {
            float end = obj->m_enumerationStart->m_motionModule->getEndFrame(kind);
            rate = end / (duration + duration * soValueAccesser::getConstantFloat(obj, 0xca0, 0));
        }
        soMotionChangeParam param;
        param.m_kind = kind;
        param.m_frame = lbl_27_rodata_20E4;
        param.m_rate = rate;
        param._12 = 0;
        param._13 = 0;
        param._14 = 0;
        param._15 = 0;
        obj->m_enumerationStart->m_motionModule->changeMotionRequest(&param);
    } else if (status == 25) {
        float rate = lbl_27_rodata_20E0;
        float duration = obj->m_enumerationStart->m_workManageModule->getFloat(0x11000000);
        if (lbl_27_rodata_20E4 != duration)
            rate = obj->m_enumerationStart->m_motionModule->getEndFrame(0x33) / duration;
        soMotionChangeParam param;
        param.m_kind = 0x33;
        param.m_frame = lbl_27_rodata_20E4;
        param.m_rate = rate;
        param._12 = 0;
        param._13 = 0;
        param._14 = 0;
        param._15 = 0;
        obj->m_enumerationStart->m_motionModule->changeMotionRequest(&param);
    }
}
