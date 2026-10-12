#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed_ground_view.h>

// The kinetic speed getter returns its trivial two-word result in r3/r4.
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

template <class T, int Offset> struct DededeEnergySlot {};
template <class T, int Offset>
inline T* getDededeEnergy(unsigned char* storage, const DededeEnergySlot<T, Offset>&) {
    return reinterpret_cast<T*>(storage + Offset);
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
inline DededeKineticSpeedView& kinetic(soModuleAccesser* accesser) {
    return reinterpret_cast<DededeKineticSpeedView&>(accesser->getKineticModule());
}
inline const DededeSpeed* speedWords(const Vec2f& speed) {
    return reinterpret_cast<const DededeSpeed*>(&speed);
}

extern "C" void fn_117_16200(const void*, unsigned char* energies, soModuleAccesser* accesser) {
    Vec2f speed;
    DededeSpeed sum = addSpeed(kinetic(accesser).getSumSpeed(soKineticEnergy::AttributeFlag(1)),
                              kinetic(accesser).getSumSpeed(soKineticEnergy::AttributeFlag(2)));
    Vec2f::copy(speed, *reinterpret_cast<const Vec2f*>(&sum));
    kinetic(accesser).unableEnergyAll();
    soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    float facing = accesser->getPostureModule().getLr();
    float horizontal = facing * params->getParamFloat(accesser, 0xfa9, 0);
    if (horizontal < lbl_117_rodata_C8) {
        if (speed.m_x < horizontal) horizontal = speed.m_x;
    } else {
        if (speed.m_x > horizontal) horizontal = speed.m_x;
    }
    unsigned char* stop = getDededeEnergy(energies, DededeEnergySlot<unsigned char, 0x10>());
    fn_117_D134(reinterpret_cast<DededeSpeed*>(stop + 8), speedWords(Vec2f(horizontal, lbl_117_rodata_C8)));
    fn_117_D134(reinterpret_cast<DededeSpeed*>(stop + 0x18), speedWords(Vec2f(params->getParamFloat(accesser, 0xfa9, 0), lbl_117_rodata_C8)));
    fn_117_D134(reinterpret_cast<DededeSpeed*>(stop + 0x20), speedWords(Vec2f(params->getParamFloat(accesser, 0xfae, 0), lbl_117_rodata_C8)));
    stop[5] |= 0x80;
}
