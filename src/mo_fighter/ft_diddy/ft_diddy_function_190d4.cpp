#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

namespace {
struct DiddySummedSpeed { float x, y; };
// The original slot returns two words in r3/r4 and takes an attribute reference.
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
float fn_115_190B0(float, float);
void fn_8003DBA8(Vec2f* vector);
extern const float lbl_115_rodata_10C;
}

extern "C" void fn_115_190D4(void*, soModuleAccesser* accesser) {
    unsigned short attributes = 1;
    Vec2f speed;
    DiddySummedSpeed summed = reinterpret_cast<DiddyKineticSpeedView*>(&accesser->getKineticModule())->getSumSpeed(attributes);
    __memcpy(&speed, &summed, sizeof(speed));
    fn_8003DBA8(&speed);
    float angle = lbl_115_rodata_10C * fn_115_190B0(speed.m_x, speed.m_y);
    Vec3f rotation = accesser->m_enumerationStart->m_modelModule->getNodeRotate(3);
    rotation.m_x = angle * accesser->m_enumerationStart->m_postureModule->getLr();
    accesser->m_enumerationStart->m_modelModule->setNodeRotate(3, &rotation);
}
