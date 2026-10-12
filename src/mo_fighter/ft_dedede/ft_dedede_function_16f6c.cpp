#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed_ground_view.h>

// Preserve the original two-word result ABI instead of Vec2f's hidden result.
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

extern "C" {
extern const float lbl_117_rodata_C8;
void fn_117_15C24(const DededeSpeed*, const DededeSpeed*, DededeSpeed*);
}

inline DededeSpeed sumSpeed(const DededeSpeed& lhs, const DededeSpeed& rhs) {
    DededeSpeed result;
    fn_117_15C24(&lhs, &rhs, &result);
    return result;
}
inline void copySpeed(Vec2f& destination, const DededeSpeed& speed) {
    Vec2f::copy(destination, *reinterpret_cast<const Vec2f*>(&speed));
}
inline const DededeSpeed* speedAddress(const Vec2f& speed) {
    return reinterpret_cast<const DededeSpeed*>(&speed);
}
struct DededeControlEnergy {
    unsigned char base[8];
    DededeSpeed speed, acceleration, stableSpeed, brake;
};
template <class T, int Offset> struct DededeControlEnergySlot {};
template <class T, int Offset>
inline T* controlEnergy(unsigned char* storage, const DededeControlEnergySlot<T, Offset>&) {
    return reinterpret_cast<T*>(storage + Offset);
}

extern "C" void fn_117_16F6C(void*, unsigned char* energies, soModuleAccesser* accesser) {
    Vec2f speed;
    copySpeed(speed, sumSpeed(
        reinterpret_cast<DededeKineticSpeedView*>(&accesser->getKineticModule())->getSumSpeed(soKineticEnergy::ATTRIBUTE_MASK_MAIN),
        reinterpret_cast<DededeKineticSpeedView*>(&accesser->getKineticModule())->getSumSpeed(soKineticEnergy::ATTRIBUTE_MASK_DAMAGE)));
    accesser->getKineticModule().unableEnergyAll();
    soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    float facing = accesser->getPostureModule().getLr();
    float horizontal = facing * params->getParamFloat(accesser, 0xfb6, 0);
    if (horizontal < lbl_117_rodata_C8) {
        if (speed.m_x < horizontal) horizontal = speed.m_x;
    } else {
        if (speed.m_x > horizontal) horizontal = speed.m_x;
    }
    DededeControlEnergy* control = controlEnergy(energies, DededeControlEnergySlot<DededeControlEnergy, 0x10>());
    fn_117_D134(&control->speed, speedAddress(Vec2f(horizontal, lbl_117_rodata_C8)));
    fn_117_D134(&control->stableSpeed, speedAddress(Vec2f(params->getParamFloat(accesser, 0xfb6, 0), lbl_117_rodata_C8)));
    fn_117_D134(&control->brake, speedAddress(Vec2f(params->getParamFloat(accesser, 0xfae, 0), lbl_117_rodata_C8)));
    reinterpret_cast<unsigned char*>(control)[5] |= 0x80;
}
