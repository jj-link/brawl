#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed.h>

// The original getter returns its trivial two-word result in r3/r4.
class DededeReboundKineticView : public soNullable {
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
    virtual DededeSpeed getSumSpeed(soKineticEnergy::AttributeFlag);
};
struct DededeReboundStopEnergy {
    unsigned char base[8];
    Vec2f speed, acceleration, brake, limit;
};
struct DededeReboundGravityEnergy {
    unsigned char base[8];
    float speed, acceleration, terminalSpeed;
};
// Compile-time selectors address the embedded energies without a lookup.
template <class T, int Offset> struct DededeReboundEnergySlot {};
template <class T, int Offset>
inline T* reboundEnergy(unsigned char* storage, const DededeReboundEnergySlot<T, Offset>&) {
    return reinterpret_cast<T*>(storage + Offset);
}
inline const DededeSpeed* speedWords(const Vec2f& speed) {
    return reinterpret_cast<const DededeSpeed*>(&speed);
}
inline DededeReboundKineticView& reboundKinetic(soModuleAccesser* accesser) {
    return reinterpret_cast<DededeReboundKineticView&>(accesser->getKineticModule());
}
extern "C" const float lbl_117_rodata_C8;

extern "C" void fn_117_16014(void*, unsigned char* energies, soModuleAccesser* accesser) {
    Vec2f speed;
    DededeSpeed sum = reboundKinetic(accesser).getSumSpeed(soKineticEnergy::AttributeFlag(1));
    Vec2f::copy(speed, *reinterpret_cast<const Vec2f*>(&sum));
    accesser->getKineticModule().unableEnergyAll();
    soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    DededeReboundStopEnergy* stop = reboundEnergy(energies, DededeReboundEnergySlot<DededeReboundStopEnergy, 0x10>());
    fn_117_D134(reinterpret_cast<DededeSpeed*>(&stop->speed), speedWords(Vec2f(-speed.m_x * params->getParamFloat(accesser, 0xfb3, 0), lbl_117_rodata_C8)));
    fn_117_D134(reinterpret_cast<DededeSpeed*>(&stop->brake), speedWords(Vec2f(params->getParamFloat(accesser, 0xfb0, 0), lbl_117_rodata_C8)));
    fn_117_D134(reinterpret_cast<DededeSpeed*>(&stop->limit), speedWords(Vec2f(params->getParamFloat(accesser, 0xfaf, 0), lbl_117_rodata_C8)));
    reinterpret_cast<unsigned char*>(stop)[5] |= 0x80;
    DededeReboundGravityEnergy* gravity = reboundEnergy(energies, DededeReboundEnergySlot<DededeReboundGravityEnergy, 0x50>());
    gravity->speed = speed.m_y + params->getParamFloat(accesser, 0xfb4, 0);
    gravity->acceleration = -params->getParamFloat(accesser, 0xfb1, 0);
    gravity->terminalSpeed = params->getParamFloat(accesser, 0xfb2, 0);
    reinterpret_cast<unsigned char*>(gravity)[5] |= 0x80;
}
