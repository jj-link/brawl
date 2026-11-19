#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/collision/so_collision_hit_module_impl.h>
#include <so/ground/so_ground_module_impl.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/posture/so_posture_module_simple.h>
#include <so/situation/so_situation_module_impl.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#include <math.h>
#pragma force_active on

class Class_7FC8 {
public:
    virtual void fn_104_7930();
    virtual void fn_104_12090();
    virtual void fn_104_12990();
    virtual void fn_104_12988();
    virtual void fn_104_12980();
    virtual void fn_104_12978();
    virtual void fn_104_12970();
    virtual void fn_104_12968();
    virtual void fn_104_12960();
    virtual void fn_104_12958();
    virtual void fn_104_12950();
    virtual void fn_104_12948();
    virtual void fn_104_12940();
    virtual void fn_104_12938();
    virtual void fn_104_128E8();
    virtual void fn_104_12930();
    virtual float fn_104_12920();
    virtual void fn_104_12910();
    virtual float fn_104_12900();
    virtual void fn_104_128F0();
};

extern "C" {
extern const float lbl_104_rodata_20[];
extern const char lbl_104_data_7138[];
extern const char lbl_104_data_2404[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_104_E724(float y, float x);
float fn_8003DDD0(const Vec2f* lhs, const Vec2f* rhs);
}

extern "C" void fn_104_E32C(void*, soModuleAccesser* accesser) {
    const float* c = lbl_104_rodata_20;

    Class_7FC8* controller;
    soPostureModule* posture;
    soKineticModule* kinetic;
    soGroundModule* ground;
    soSituationModule* situation;
    soCollisionHitModule* hit;
    int flag = 0;

    controller = reinterpret_cast<Class_7FC8*>(accesser->m_enumerationStart->m_controllerModule);
    posture = accesser->m_enumerationStart->m_postureModule;
    kinetic = accesser->m_enumerationStart->m_kineticModule;
    ground = accesser->m_enumerationStart->m_groundModule;
    situation = accesser->m_enumerationStart->m_situationModule;
    hit = accesser->m_enumerationStart->m_collisionHitModule;

    ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(13));
    const float* params = *reinterpret_cast<const float* const*>(reinterpret_cast<const char*>(data) + 0x84);

    Vec2f stick(controller->fn_104_12920(), controller->fn_104_12900());
    Vec2f speed;
    float lengthSq = stick.lengthSq();
    float len;
    if (static_cast<float>(static_cast<double>(nw4r::math::FAbs(lengthSq))) <= c[1]) {
        len = c[0];
    } else {
        len = lengthSq * rsqrtf(lengthSq);
    }
    if (len > c[2]) {
        len = c[2];
    }

    float cosA;
    float angle;

    if (len < params[6]) {
        flag = 1;
    } else if (ground->isTouch(static_cast<grCollStatus::TouchMask>(0xff), 0)) {
        Vec2f normal;
        Vec2f::copy(normal, ground->getTouchNormal(static_cast<grCollStatus::TouchMask>(0xff), 0));
        if (fn_8003DDD0(&normal, &stick) < c[3]) {
            flag = 1;
        }
        if (ground->isPassableGround(0)) {
            flag = 1;
        }
    } else {
        flag = 1;
    }

    if (stick.m_x > c[4]) {
        posture->setLr(c[2]);
    } else if (stick.m_x < c[5]) {
        posture->setLr(c[6]);
    }
    posture->updateRotYLr();

    if (flag != 0) {
        if (len > params[6]) {
            angle = fn_104_E724(stick.m_y, stick.m_x * posture->getLr());
        } else {
            angle = c[3];
            len = c[2];
        }

        cosA = static_cast<float>(cos(angle));
        float lr2 = posture->getLr();
        float a = params[8] + params[7] * len;
        a *= cosA;
        speed.m_x = a * lr2;

        speed.m_y = (params[8] + params[7] * len) * static_cast<float>(sin(angle));
        situation->setKind(static_cast<SituationKind>(2), false);
        ground->setCorrect(static_cast<soGroundShapeImpl::CorrectKind>(5), 0);
    } else {
        angle = fn_104_E724(stick.m_y, stick.m_x * posture->getLr());

        cosA = static_cast<float>(cos(angle));
        float lr2 = posture->getLr();
        float a = params[8] + params[7] * len;
        a *= cosA;
        speed.m_x = a * lr2;
        speed.m_y = c[0];
    }

    kinetic->clearSpeedAll();
    short mask = 1;
    unsigned char* energy = (unsigned char*)__dynamic_cast(kinetic->getEnergy(3), 0, lbl_104_data_7138, lbl_104_data_2404, mask);
    *(float*)(energy + 8) = speed.m_x;
    *(float*)(energy + 0xC) = speed.m_y;
    energy[5] |= 0x80;

    hit->setWhole(2, 0);
}
