#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

struct PikachuSummedSpeed { float x, y; };
// This entry returns a POD speed pair in r3/r4, rather than a Vec2f sret.
class PikachuKineticSpeedView : public soNullable {
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
    virtual PikachuSummedSpeed getSumSpeed(const unsigned short&);
};
struct PikachuEnergyEnableView {
    void* vtable;
    unsigned char nullable;
    unsigned char enabled : 1;
    unsigned char : 7;
};
extern "C" {
extern const char lbl_98_data_723C[], lbl_98_data_24B0[];
extern const float lbl_98_rodata_68;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_98_F5B0(Vec3f*, float, float, float);
}
#pragma always_inline on
#pragma inline_depth(8)
extern "C" void fn_98_10C18(void*, soModuleAccesser* accesser) {
    soKineticModule& kinetic = accesser->getKineticModule();
    unsigned short attributes = 1;
    Vec2f speed;
    PikachuSummedSpeed summed = reinterpret_cast<PikachuKineticSpeedView*>(&kinetic)->getSumSpeed(attributes);
    __memcpy(&speed, &summed, sizeof(speed));
    soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
        kinetic.getEnergy(3), 0, lbl_98_data_723C, lbl_98_data_24B0, 1));
    float divisor = soValueAccesser::getConstantFloat(accesser, 0xfb1, 0);
    Vec2f horizontal(speed.m_x / divisor, lbl_98_rodata_68);
    Vec3f rotation;
    stop->resetEnergy(6, &horizontal, fn_98_F5B0(&rotation,
        lbl_98_rodata_68, lbl_98_rodata_68, lbl_98_rodata_68), accesser);
    reinterpret_cast<PikachuEnergyEnableView*>(stop)->enabled = 1;
    reinterpret_cast<signed char*>(kinetic.getEnergy(2))[5] &= ~0x80;
}
