#include <gm/gm_global.h>
#include <gm/gm_stage_data.h>
#pragma force_active on

extern const float lbl_27_rodata_33D8;

class Stage {
public:
    void setMotionSubRatio(float, float);
};

void Stage::setMotionSubRatio(float a, float b) {
    float k = lbl_27_rodata_33D8;
    if (k == b) {
        gmStageData* sd = g_GameGlobal->m_stageData;
        sd->m_motionSubRatio = a;
        float* p = (float*)((char*)this + 0xd8);
        p[0] = k;
        p[1] = k;
        p[2] = k;
        p[3] = k;
    } else {
        gmStageData* sd = g_GameGlobal->m_stageData;
        float* p = (float*)((char*)this + 0xd8);
        p[0] = sd->m_motionSubRatio;
        p[1] = a;
        p[2] = k;
        p[3] = b;
    }
}
