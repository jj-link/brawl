#pragma always_inline on
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#include <mt/mt_prng.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma scheduling off

namespace {
struct DiddySummedSpeed { float x, y; };
class DiddyKineticView : public soNullable {
public:
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy(soKineticEnergy*, int, soKineticEnergy::AttributeFlag, short);
    virtual void eraseEnergy(int);
    virtual void eraseEnergyAll();
    virtual soKineticEnergy* getEnergy(int);
    virtual bool isContain(int);
    virtual void updateEnergy(soModuleAccesser*, soKineticEnergy::AttributeFlag);
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual DiddySummedSpeed getSumSpeed(const unsigned short&);
};
}

extern "C" {
extern const float lbl_115_rodata_108[];
extern const char lbl_115_data_7488[], lbl_115_data_A23C[], lbl_115_data_2760[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_115_190B0(float, float);
void fn_8003DBA8(Vec2f*);
void fn_8003DC64(Vec2f*, float, Vec2f*);
}

class soKineticEnergyNormal : public soKineticEnergy {
public:
    Vec2f speed;
};

class wnKineticEnergyGravity : public soKineticEnergy {
public:
    float speed;
};

extern "C" void fn_115_18980(void*, soModuleAccesser* accesser) {
    const float* c = lbl_115_rodata_108;
    soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    accesser->getWorkManageModule().getInt(0x20000000);
    switch (accesser->getStatusModule().getStatusKind()) {
    case 1: {
        int one = 1;
        soKineticEnergyNormal* e0 = static_cast<soKineticEnergyNormal*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(0), 0, lbl_115_data_7488, lbl_115_data_2760, one));
        wnKineticEnergyGravity* e1 = static_cast<wnKineticEnergyGravity*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(1), 0, lbl_115_data_A23C, lbl_115_data_2760, one));
        float lr = accesser->getPostureModule().getLr();
        accesser->getWorkManageModule().addInt(-1, 0x20000001);
        if (accesser->getWorkManageModule().getInt(0x20000001) <= 0 ||
            accesser->getWorkManageModule().isFlag(0x22000000)) {
            float rnd = c[0] * randf();
            accesser->getWorkManageModule().setFloat(rnd, 0x21000001);
            int n = params->getParamInt(accesser, 0x5DC2, 0);
            if (params->getParamInt(accesser, 0x5DC3, 0) > 0) {
                n += randi(params->getParamInt(accesser, 0x5DC3, 0));
            }
            accesser->getWorkManageModule().setInt(n, 0x20000001);
            accesser->getWorkManageModule().offFlag(0x22000000);
        }
        Vec2f v1;
        Vec2f v2;
        Vec2f vec;
        unsigned short attr1 = one;
        DiddySummedSpeed summed1 = reinterpret_cast<DiddyKineticView*>(&accesser->getKineticModule())->getSumSpeed(attr1);
        __memcpy(&v1, &summed1, sizeof(v1));
        unsigned short attr2 = one;
        DiddySummedSpeed summed2 = reinterpret_cast<DiddyKineticView*>(&accesser->getKineticModule())->getSumSpeed(attr2);
        __memcpy(&v2, &summed2, sizeof(v2));
        fn_8003DBA8(&v2);
        float ang = c[1] * fn_115_190B0(v2.m_x, v2.m_y);
        if (ang < c[2]) {
            ang = c[0] + ang;
        }
        float diff = accesser->getWorkManageModule().getFloat(0x21000001) - ang;
        float sq;
        float dir;
        float adiff = nw4r::math::FAbs(diff);
        if (diff > c[2]) {
            if (diff - c[3] < c[2]) dir = c[4]; else dir = c[5];
        } else {
            if (adiff - c[3] < c[2]) dir = c[5]; else dir = c[4];
        }
        float step = adiff;
        if (lr >= c[2]) {
            if (dir > c[2]) {
                if (adiff > params->getParamFloat(accesser, 0xFA3, 0)) step = params->getParamFloat(accesser, 0xFA3, 0);
            } else {
                if (adiff > params->getParamFloat(accesser, 0xFA2, 0)) step = params->getParamFloat(accesser, 0xFA2, 0);
            }
        } else {
            if (dir > c[2]) {
                if (adiff > params->getParamFloat(accesser, 0xFA2, 0)) step = params->getParamFloat(accesser, 0xFA2, 0);
            } else {
                if (adiff > params->getParamFloat(accesser, 0xFA3, 0)) step = params->getParamFloat(accesser, 0xFA3, 0);
            }
        }
        if (step == adiff) {
            accesser->getWorkManageModule().onFlag(0x22000000);
        }
        step *= dir;
        ang += step;
        if (ang > c[0]) {
            ang -= c[0];
        }
        sq = v1.m_x * v1.m_x + v1.m_y * v1.m_y;
        float mag;
        if (static_cast<float>(static_cast<double>(nw4r::math::FAbs(sq))) <= c[6]) {
            mag = c[2];
        } else {
            mag = sq * rsqrtf(sq);
        }
        if (accesser->getWorkManageModule().getInt(0x20000002) > 0) {
            accesser->getWorkManageModule().addInt(-1, 0x20000002);
            if (mag < accesser->getWorkManageModule().getFloat(0x21000002)) {
                mag = accesser->getWorkManageModule().getFloat(0x21000002);
            }
        }
        vec.m_x = c[2];
        vec.m_y = mag;
        fn_8003DC64(&vec, c[7] * (c[0] - ang), &vec);
        float speed[2] = {vec.m_x, c[2]};
        const Vec2f& horizontal = *reinterpret_cast<const Vec2f*>(speed);
        e0->speed.m_x = horizontal.m_x;
        e0->speed.m_y = horizontal.m_y;
        e1->speed = vec.m_y;
        Vec3f rot = accesser->m_enumerationStart->m_modelModule->getNodeRotate(3);
        rot.m_x = ang * lr;
        accesser->m_enumerationStart->m_modelModule->setNodeRotate(3, &rot);
        float p7 = params->getParamFloat(accesser, 0xFA7, 0);
        float p6 = params->getParamFloat(accesser, 0xFA6, 0);
        float ratio = mag / p6;
        float power = ratio * p7;
        accesser->m_enumerationStart->m_collisionAttackModule->setPowerAddStatus(power);
        break;
    }
    }
}