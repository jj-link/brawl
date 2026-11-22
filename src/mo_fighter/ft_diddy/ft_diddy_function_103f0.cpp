#include <types.h>
#include <math.h>
#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#include <string.h>
#pragma force_active on
#pragma pool_data on
#pragma pool_fp_consts on

namespace {
struct DiddySummedSpeed {
    float x;
    float y;
};

class DiddyKineticSpeedView : public soNullable {
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
double atan2(double, double);
float fn_115_E59C(float value);
void fn_8003DBA8(Vec2f* vector);
extern const float lbl_115_rodata_70[];
}

extern "C" float fn_115_103F0(void*, soModuleAccesser* accesser, float limit) {
    float pool;
    double bias;
    bias = 2097152.509765625;
    pool = 24.0f;
    pool = 12.0f;
    pool = 0.01745329238474369f;
    pool = 0.0f;
    bias = 1.4411521631526584e+18;
    bias = 4503601774854144.0;
    bias = 0.19579640089068562;
    pool = 57.295780181884766f;
    pool = 180.0f;
    unsigned short attributes = 1;
    Vec2f speed;
    DiddySummedSpeed summed =
        reinterpret_cast<DiddyKineticSpeedView*>(&accesser->getKineticModule())
            ->getSumSpeed(attributes);
    __memcpy(&speed, &summed, sizeof(speed));
    fn_8003DBA8(&speed);

    float lr = accesser->getPostureModule().getLr();
    float y = speed.m_y;
    float x = speed.m_x;
    float angle = lr * (57.295780181884766f * (float)atan2(x, y));
    float value = accesser->getWorkManageModule().getFloat(0x2100000D);
    float a = fn_115_E59C(angle);
    float diff = fn_115_E59C(value) - a;

    if (0.0f == value && 180.0f == fn_115_E59C(diff)) {
        accesser->getWorkManageModule().onFlag(0x22000018);
    }

    if (accesser->getWorkManageModule().isFlag(0x22000018)) {
        angle = fn_115_E59C(angle);
    }

    if (fn_115_E59C(diff) > limit) {
        signed int sign = (angle < 0.0f) ? -1 : 1;
        angle = value + limit * (float)sign;
    }

    Vec3f rot = accesser->getModelModule().getNodeRotate(5);
    rot.m_x = angle;
    accesser->getModelModule().setNodeRotate(5, &rot);
    return rot.m_x;
}
