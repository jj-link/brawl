#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

struct LuigiFallSpeed { float x, y; };
// Individual energy speed uses the original two-register POD return ABI.
class LuigiFallEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual LuigiFallSpeed getSpeed();
};
extern "C" {
extern const char lbl_99_data_6244[], lbl_99_data_639C[], lbl_99_data_171C[];
extern const float lbl_99_rodata_10;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec2f* fn_99_AA80(Vec2f*, const Vec2f*);
void fn_27_15FBC8(int);
}

extern "C" void fn_99_C338(void*, int, const void*, soModuleAccesser* accesser) {
    Vec2f speed;
    fn_27_15FBC8(10);
    soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(3), 0,
        lbl_99_data_6244, lbl_99_data_171C, 1));
    Vec2f limit(soValueAccesser::getConstantFloat(accesser, 0xfb7, 0), lbl_99_rodata_10);
    fn_99_AA80(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(stop) + 0x20), &limit);
    soKineticEnergy* gravity = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(1), 0,
        lbl_99_data_639C, lbl_99_data_171C, 1));
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(gravity) + 0x10) =
        -soValueAccesser::getConstantFloat(accesser, 0xfb8, 0);
    if (accesser->getWorkManageModule().isFlag(0x22000014) == false &&
        accesser->getWorkManageModule().isFlag(0x22000013) == true) {
        Vec2f stopSpeed(lbl_99_rodata_10, lbl_99_rodata_10);
        fn_99_AA80(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(stop) + 8), &stopSpeed);
        LuigiFallSpeed returnedSpeed = reinterpret_cast<LuigiFallEnergyView*>(gravity)->getSpeed();
        __memcpy(&speed, &returnedSpeed, sizeof(speed));
        if (speed.m_y > lbl_99_rodata_10)
            *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(gravity) + 0x0c) = lbl_99_rodata_10;
    }
}
