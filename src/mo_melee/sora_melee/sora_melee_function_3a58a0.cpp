#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

namespace {
struct SummedSpeed { float x, y; };
class KineticSpeedView : public soNullable {
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
    virtual SummedSpeed getSumSpeed(const unsigned short&);
};
}

extern "C" {
double atan2(double, double);
void fn_8003DBA8(Vec2f* vector);
extern const float lbl_27_rodata_7ED8;
}

static inline float atan2Float(float y, float x) {
    return atan2(y, x);
}

extern "C" void fn_27_3A58A0(void*, soModuleAccesser* accesser) {
    Vec3f rotation = accesser->m_enumerationStart->m_postureModule->getRot(0);
    unsigned short attributes = 1;
    SummedSpeed summed = reinterpret_cast<KineticSpeedView*>(&accesser->getKineticModule())->getSumSpeed(attributes);
    Vec2f speed;
    __memcpy(&speed, &summed, sizeof(speed));
    fn_8003DBA8(&speed);
    rotation.m_x = lbl_27_rodata_7ED8 * -atan2Float(speed.m_y, speed.m_x * accesser->m_enumerationStart->m_postureModule->getLr());
    accesser->m_enumerationStart->m_postureModule->setRot(&rotation, 0);
}
