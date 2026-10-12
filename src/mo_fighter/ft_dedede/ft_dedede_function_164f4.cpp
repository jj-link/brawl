#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed.h>

// The kinetic getter returns the trivial two-word speed in r3/r4.
class DededeKineticSpeedView : public soNullable {
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
struct DededeLaunchStopEnergy {
    unsigned char base[8];
    Vec2f speed, acceleration, brake, limit;
};
template <class T, int Offset> struct DededeLaunchEnergySlot {};
template <class T, int Offset>
inline T* launchEnergy(unsigned char* storage, const DededeLaunchEnergySlot<T, Offset>&) {
    return reinterpret_cast<T*>(storage + Offset);
}
inline DededeKineticSpeedView& kinetic(soModuleAccesser* accesser) {
    return reinterpret_cast<DededeKineticSpeedView&>(accesser->getKineticModule());
}
extern "C" {
extern const float lbl_117_rodata_C8;
void fn_117_15C24(const DededeSpeed*, const DededeSpeed*, DededeSpeed*);
}
inline DededeSpeed addSpeed(const DededeSpeed& lhs, const DededeSpeed& rhs) {
    DededeSpeed result;
    fn_117_15C24(&lhs, &rhs, &result);
    return result;
}
inline const DededeSpeed* speedWords(const Vec2f& speed) {
    return reinterpret_cast<const DededeSpeed*>(&speed);
}

extern "C" void fn_117_164F4(void*, unsigned char* energies, soModuleAccesser* accesser) {
    Vec2f speed;
    DededeSpeed sum = addSpeed(kinetic(accesser).getSumSpeed(soKineticEnergy::AttributeFlag(1)),
                              kinetic(accesser).getSumSpeed(soKineticEnergy::AttributeFlag(2)));
    Vec2f::copy(speed, *reinterpret_cast<const Vec2f*>(&sum));
    kinetic(accesser).unableEnergyAll();
    soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    DededeLaunchStopEnergy* stop = launchEnergy(energies, DededeLaunchEnergySlot<DededeLaunchStopEnergy, 0x10>());
    fn_117_D134(reinterpret_cast<DededeSpeed*>(&stop->speed), speedWords(Vec2f(speed.m_x, lbl_117_rodata_C8)));
    fn_117_D134(reinterpret_cast<DededeSpeed*>(&stop->brake), speedWords(Vec2f(lbl_117_rodata_C8, lbl_117_rodata_C8)));
    fn_117_D134(reinterpret_cast<DededeSpeed*>(&stop->limit), speedWords(Vec2f(params->getParamFloat(accesser, 0xfae, 0), lbl_117_rodata_C8)));
    reinterpret_cast<unsigned char*>(stop)[5] |= 0x80;
}
