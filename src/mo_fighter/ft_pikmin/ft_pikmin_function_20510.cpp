#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
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
    virtual Speed getSumSpeed(short&);
};
class Class_72D0 {
public:
    virtual void fn_113_12414();
    virtual void fn_113_11EBC();
    virtual void fn_113_11ECC();
    virtual void fn_113_13A6C();
    virtual void fn_113_12484();
    virtual void fn_113_13990();
    virtual void fn_113_11FD0();
    virtual void fn_113_12084();
    virtual void fn_113_123CC();
    virtual void fn_113_11EDC();
    virtual void fn_113_11C60();
    virtual void fn_113_12138();
    virtual void fn_113_12250();
    virtual void fn_113_13A64();
};
template <class T, int Offset> struct EnergySlot {};
template <class T, int Offset>
inline T* energy(unsigned char* storage) {
    return reinterpret_cast<T*>(storage + Offset);
}
struct Gravity { char base[8]; float speed; };
struct Temp { char data[0x14]; };
struct Flag { unsigned char value; };
extern "C" {
extern const float lbl_113_rodata_90, lbl_113_rodata_94;
void fn_113_1E820(Flag*, void*, soModuleAccesser*);
Temp* fn_113_205EC(Temp*, float, float, float);
void* fn_113_20654(void*, Temp*);
void fn_113_4730(Temp*, short);
}
extern "C" void fn_113_20510(void*, unsigned char* owner, soModuleAccesser* accesser) {
    Vec2f speed;
    short attr = 1;
    Speed sum = reinterpret_cast<KineticView&>(accesser->getKineticModule()).getSumSpeed(attr);
    Vec2f::copy(speed, *reinterpret_cast<Vec2f*>(&sum));
    Flag flag = {0};
    fn_113_1E820(&flag, owner, accesser);
    Flag flag2 = {0};
    reinterpret_cast<Class_72D0*>(owner + 0x10)->fn_113_13A64();
    Flag flag3 = {0};
    Gravity* gravity = energy<Gravity, 0x50>(owner);
    Temp temp;
    fn_113_205EC(&temp, lbl_113_rodata_90, lbl_113_rodata_90, lbl_113_rodata_94);
    fn_113_20654(gravity, &temp);
    fn_113_4730(&temp, 0);
    gravity->speed = speed.m_y;
}