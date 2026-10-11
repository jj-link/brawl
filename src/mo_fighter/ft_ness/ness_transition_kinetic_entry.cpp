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

extern "C" {
extern const char lbl_101_data_884C[], lbl_101_data_8BEC[], lbl_101_data_3890[];
extern const float lbl_101_rodata_58, lbl_101_rodata_5C;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec2f* fn_101_FE5C(Vec2f*, const Vec2f*);
float fn_101_BD7C(float, float);
}

extern "C" void fn_101_11D78(void*, soModuleAccesser* accesser)
{
    soWorkManageModule& work = accesser->getWorkManageModule();
    soSituationModule& situation = accesser->getSituationModule();
    soKineticModule& kinetic = accesser->getKineticModule();
    soPostureModule& posture = accesser->getPostureModule();
    soGroundModule& ground = accesser->getGroundModule();
    soModelModule& model = accesser->getModelModule();
    ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(10));
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
        speed.m_y = lbl_101_rodata_58;
    }

    void* stopEnergy = __dynamic_cast(kinetic.getEnergy(3), 0,
        lbl_101_data_884C, lbl_101_data_3890, 1);
    void* gravityEnergy = __dynamic_cast(kinetic.getEnergy(1), 0,
        lbl_101_data_8BEC, lbl_101_data_3890, 1);
    // Original energy layouts and unchecked cast-result address arithmetic.
    fn_101_FE5C(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned long>(stopEnergy) + 8), &speed);
    *reinterpret_cast<float*>(reinterpret_cast<unsigned long>(gravityEnergy) + 0xC) = lbl_101_rodata_58;
    if (situation.getKind() == 0) {
        kinetic.changeKinetic(0x67, accesser);
    } else {
        kinetic.changeKinetic(0x68, accesser);
    }
    float rotation = fn_101_BD7C(speed.m_y, speed.m_x * lr);
    model.setNodeRotateZ(5, lbl_101_rodata_5C * rotation);
    accesser->getStageObject().updateNodeSRT();
}
