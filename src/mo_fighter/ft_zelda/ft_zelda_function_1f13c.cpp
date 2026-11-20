#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/controller/so_controller_module_impl.h>
#include <so/ground/so_ground_module_impl.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/posture/so_posture_module_simple.h>
#include <so/situation/so_situation_module_impl.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern "C" {
extern const float lbl_104_rodata_158[];
extern const char lbl_104_data_7138[];
extern const char lbl_104_data_2404[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_104_1F4EC(Vec2f*, Vec2f*);
void fn_104_CDE4(Vec2f*, const Vec2f*);
float fn_104_E724(float, float);
double cos(double);
double sin(double);
float mtSqrtf__Ff(float);
}

extern "C" void fn_104_1F13C(void*, soModuleAccesser* accesser)
{
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    soControllerModule* controller = modules->m_controllerModule;
    soSituationModule* situation = modules->m_situationModule;
    soKineticModule* kinetic = modules->m_kineticModule;
    soPostureModule* posture = modules->m_postureModule;
    soGroundModule* ground = modules->m_groundModule;

    Vec2f speed;
    Vec2f stick;
    Vec2f touchNormal;

    char* params = *(char**)((char*)g_ftCommonDataAccesser.getData(static_cast<ftKind>(14)) + 0x84);
    char* stop = (char*)__dynamic_cast(kinetic->getEnergy(3), 0, lbl_104_data_7138, lbl_104_data_2404, 1);

    int flag = 0;
    stick.m_x = controller->getStickX();
    stick.m_y = controller->getStickY();

    float var_f31 = mtSqrtf__Ff(stick.m_x * stick.m_x + stick.m_y * stick.m_y);
    float maxLength = 1.0f;
    if (var_f31 > maxLength) {
        var_f31 = maxLength;
    }

    float f30;
    float f29;

    if (situation->getKind() == 0) {
        if (var_f31 < *(float*)(params + 0x14)) {
            flag = 1;
        } else {
            Vec2f::copy(touchNormal, ground->getTouchNormal(static_cast<grCollStatus::TouchMask>(8), 0));
            if (fn_104_1F4EC(&stick, &touchNormal) < 1.5707963705062866f) {
                flag = 1;
            } else if (ground->isPassableGround(0) != 0) {
                flag = 1;
            }
        }
    } else {
        flag = 1;
    }

    if (flag != 0) {
        if (var_f31 > *(float*)(params + 0x14)) {
            if (nw4r::math::FAbs(stick.m_x) > 0.001f) {
                posture->setStickLR(0.0f);
                posture->updateRotYLr();
            }
            f30 = posture->getLr();
            f29 = fn_104_E724(stick.m_y, stick.m_x * f30);
        } else {
            posture->setStickLR(0.0f);
            posture->updateRotYLr();
            f30 = posture->getLr();
            f29 = 1.5707963705062866f;
            var_f31 = 1.0f;
        }
    } else {
        posture->setStickLR(0.0f);
        posture->updateRotYLr();
        f30 = posture->getLr();
        f29 = fn_104_E724(stick.m_y, stick.m_x * f30);
    }

    situation->setKind(static_cast<SituationKind>(2), false);
    ground->setCorrect(static_cast<soGroundShapeImpl::CorrectKind>(5), 0);
    kinetic->clearSpeedAll();

    speed.m_x = f30 * ((*(float*)(params + 0x1C) + var_f31 * *(float*)(params + 0x18)) * (float)cos(f29));
    speed.m_y = (*(float*)(params + 0x1C) + var_f31 * *(float*)(params + 0x18)) * (float)sin(f29);
    fn_104_CDE4((Vec2f*)(stop + 8), &speed);
    stop[5] |= 0x80;
}
