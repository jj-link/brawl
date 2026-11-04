#include <so/so_module_accesser.h>
#include <math.h>
#pragma force_active on

struct Speed { float x, y; };
class KineticView : public soNullable {
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
    virtual Speed getSumSpeed(const unsigned short&);
};
struct Owner { char pad[0x60]; soModuleAccesser* accesser; };
extern float lbl_27_rodata_798C;
extern "C" void fn_27_355A04(Owner* obj) {
    unsigned short attributes = 1;
    Vec2f speed;
    Speed sum = reinterpret_cast<KineticView*>(&obj->accesser->getKineticModule())->getSumSpeed(attributes);
    __memcpy(&speed, &sum, sizeof(speed));
    float angle = atan2(speed.m_y, speed.m_x * -obj->accesser->getPostureModule().getLr());
    Vec3f pos = obj->accesser->getPostureModule().getPos();
    Vec3f rot = obj->accesser->getPostureModule().getRot(0);
    rot.m_x = lbl_27_rodata_798C * angle;
    rot.m_y += obj->accesser->getPostureModule().getRotYLr();
    float s = obj->accesser->getPostureModule().getScale();
    Vec3f scale;
    scale.m_x = scale.m_y = scale.m_z = s;
    scale.m_z *= obj->accesser->getWorkManageModule().getFloat(0x11000001);
    obj->accesser->getModelModule().setNodeSRT(0, &scale, &rot, &pos);
}