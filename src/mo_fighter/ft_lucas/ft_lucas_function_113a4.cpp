#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#include <so/ground/so_ground_module_impl.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/model/so_model_module_simple.h>
#include <so/posture/so_posture_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <math.h>
#pragma force_active on

extern "C" {
extern const char lbl_114_data_8040[], lbl_114_data_8394[], lbl_114_data_31DC[];
extern const float lbl_114_rodata_60, lbl_114_rodata_64;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec2f* fn_114_F6BC(Vec2f*, const Vec2f*);
float fn_114_B6DC(float, float);
}

extern "C" void fn_114_113A4(void*, soModuleAccesser* accesser)
{
    soWorkManageModule& work = accesser->getWorkManageModule();
    soSituationModule& situation = accesser->getSituationModule();
    soKineticModule& kinetic = accesser->getKineticModule();
    soPostureModule& posture = accesser->getPostureModule();
    soGroundModule& ground = accesser->getGroundModule();
    soModelModule& model = accesser->getModelModule();
    ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(0x1A));
    const unsigned char* parameters =
        *reinterpret_cast<const unsigned char**>(reinterpret_cast<unsigned char*>(data) + 0x84);
    float lr = posture.getLr();
    float angle = work.getFloat(0x21000004);
    Vec2f speed;
    if (work.isFlag(0x22000011)) {
        ground.setCorrect(soGroundShapeImpl::Correct_Air, 0);
        situation.setKind(static_cast<SituationKind>(2), false);
        float cosine = cos(angle);
        speed.m_x = lr * (*reinterpret_cast<const float*>(parameters + 0x18) * cosine);
        float sine = sin(angle);
        speed.m_y = *reinterpret_cast<const float*>(parameters + 0x18) * sine;
    } else {
        ground.setCorrect(soGroundShapeImpl::Correct_Ground, 0);
        situation.setKind(static_cast<SituationKind>(0), false);
        speed.m_x = *reinterpret_cast<const float*>(parameters + 0x18) * lr;
        speed.m_y = lbl_114_rodata_60;
    }

    void* stopEnergy = __dynamic_cast(kinetic.getEnergy(3), 0,
        lbl_114_data_8040, lbl_114_data_31DC, 1);
    void* gravityEnergy = __dynamic_cast(kinetic.getEnergy(1), 0,
        lbl_114_data_8394, lbl_114_data_31DC, 1);
    fn_114_F6BC(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned long>(stopEnergy) + 8), &speed);
    *reinterpret_cast<float*>(reinterpret_cast<unsigned long>(gravityEnergy) + 0xC) = lbl_114_rodata_60;
    if (situation.getKind() == 0) {
        kinetic.changeKinetic(0x67, accesser);
    } else {
        kinetic.changeKinetic(0x68, accesser);
    }
    float rotation = fn_114_B6DC(speed.m_y, speed.m_x * lr);
    model.setNodeRotateZ(3, lbl_114_rodata_64 * rotation);
    accesser->getStageObject().updateNodeSRT();
}
