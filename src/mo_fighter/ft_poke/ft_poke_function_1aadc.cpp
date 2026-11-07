#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct PokeSpeed { float x, y; };

class PokeEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual PokeSpeed getSpeed();
};

extern "C" {
extern const char lbl_116_data_6E04[], lbl_116_data_2260[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_116_CB3C(Vec2f*, const Vec2f*);
void fn_27_15FBC8(int);
}

extern "C" void fn_116_1AADC(void*, int, const void*, soModuleAccesser* accesser) {
    fn_27_15FBC8(6);
    if (accesser->getWorkManageModule().isFlag(0x22000010) == false) {
        soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(3), 0,
            lbl_116_data_6E04, lbl_116_data_2260, 1));
        Vec2f speed;
        PokeSpeed returnedSpeed = reinterpret_cast<PokeEnergyView*>(energy)->getSpeed();
        __memcpy(&speed, &returnedSpeed, sizeof(speed));
        speed.m_x *= soValueAccesser::getConstantFloat(accesser, 0xfbc, 0);
        fn_116_CB3C(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 8), &speed);
    }
}
