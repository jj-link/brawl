#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

struct LuigiBrakeSpeed { float x, y; };
// Individual energy speed uses the original two-register POD return ABI.
class LuigiBrakeEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual LuigiBrakeSpeed getSpeed();
};
extern "C" {
extern const char lbl_99_data_6244[], lbl_99_data_171C[];
extern const float lbl_99_rodata_10;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec2f* fn_99_AA80(Vec2f*, const Vec2f*);
void fn_27_15FBC8(int);
}

extern "C" void fn_99_BE98(void*, int, const void*, soModuleAccesser* accesser) {
    fn_27_15FBC8(13);
    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(3), 0,
        lbl_99_data_6244, lbl_99_data_171C, 1));
    if (accesser->getWorkManageModule().isFlag(0x22000010) == false) {
        Vec2f speed;
        LuigiBrakeSpeed returnedSpeed = reinterpret_cast<LuigiBrakeEnergyView*>(energy)->getSpeed();
        __memcpy(&speed, &returnedSpeed, sizeof(speed));
        speed.m_x /= soValueAccesser::getConstantFloat(accesser, 0xfad, 0);
        fn_99_AA80(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 8), &speed);
    }
    Vec2f limit(soValueAccesser::getConstantFloat(accesser, 0xfae, 0), lbl_99_rodata_10);
    fn_99_AA80(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 0x20), &limit);
}
