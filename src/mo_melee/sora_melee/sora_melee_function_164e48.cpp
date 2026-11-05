#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_1FF0[];
}

extern "C" void fn_27_164E48(soModuleAccesser* accesser, int* kinds, int valueId, int rateId, float base) {
    const float* c = lbl_27_rodata_1FF0;
    float speed = (float)(double)nw4r::ut::Abs(accesser->m_enumerationStart->m_workManageModule->getFloat(valueId));
    soMotionModule* motion = accesser->m_enumerationStart->m_motionModule;
    if (motion->isBlend() == 1) {
        int kind = motion->getKind();
        float rate;
        if (kind == kinds[2])
            rate = speed / (c[4] * base);
        else if (kind == kinds[1])
            rate = speed / (c[3] * ((c[3] * base) + (c[2] * base)));
        else
            rate = speed / base;
        rate *= accesser->m_enumerationStart->m_workManageModule->getFloat(rateId);
        float limit = soValueAccesser::getConstantFloat(accesser, 0xC30, 0);
        if (rate > limit) rate = limit;
        motion->setRate(rate);
        kind = motion->get2ndKind();
        if (kind == kinds[2])
            rate = speed / (c[4] * base);
        else if (kind == kinds[1])
            rate = speed / (c[3] * ((c[3] * base) + (c[2] * base)));
        else
            rate = speed / base;
        rate *= accesser->m_enumerationStart->m_workManageModule->getFloat(rateId);
        limit = soValueAccesser::getConstantFloat(accesser, 0xC30, 0);
        if (rate > limit) rate = limit;
        motion->set2ndRate(rate);
    } else {
        int kind;
        if (speed >= c[2] * base) kind = kinds[0];
        else if (speed >= c[3] * base) kind = kinds[1];
        else kind = kinds[2];
        float rate;
        if (kind == kinds[2])
            rate = speed / (c[4] * base);
        else if (kind == kinds[1])
            rate = speed / (c[3] * ((c[3] * base) + (c[2] * base)));
        else
            rate = speed / base;
        rate *= accesser->m_enumerationStart->m_workManageModule->getFloat(rateId);
        float limit = soValueAccesser::getConstantFloat(accesser, 0xC30, 0);
        if (rate > limit) rate = limit;
        if (kind != motion->getKind()) {
            float end = motion->getEndFrame(kind);
            float oldEnd = motion->getEndFrame();
            float frame = motion->getFrame();
            soMotionChangeParam param;
            param.m_kind = kind;
            param.m_frame = end * (frame / oldEnd);
            param.m_rate = rate;
            param._12 = 0;
            param._13 = 0;
            param._14 = 0;
            param._15 = 0;
            motion->changeMotion(&param);
            int second = motion->get2ndKind();
            float secondRate;
            if (second == kinds[2]) secondRate = speed / c[4];
            else if (second == kinds[1]) secondRate = speed / c[5];
            else secondRate = speed / c[6];
            secondRate *= accesser->m_enumerationStart->m_workManageModule->getFloat(0x21000005);
            limit = soValueAccesser::getConstantFloat(accesser, 0xC30, 0);
            if (secondRate > limit) secondRate = limit;
            motion->set2ndRate(secondRate);
        } else {
            motion->setRate(rate);
        }
    }
}
