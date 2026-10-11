#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

struct LuigiGroundResetSpeed { float x, y; };
struct LuigiGroundResetEnable { unsigned char enabled : 1; };
extern "C" {
extern const char lbl_99_data_6358[], lbl_99_data_171C[];
extern const float lbl_99_rodata_10, lbl_99_rodata_20;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_99_C610(Vec3f*, float, float, float);
Vec2f* fn_99_AA80(Vec2f*, const Vec2f*);
}

extern "C" void fn_99_C4C8(void*, int, const LuigiGroundResetSpeed* input,
                           soModuleAccesser* accesser) {
    Vec2f speed;
    __memcpy(&speed, input, sizeof(speed));
    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(2), 0,
        lbl_99_data_6358, lbl_99_data_171C, 1));
    Vec3f rotation;
    energy->resetEnergy(0x11, &speed, fn_99_C610(&rotation,
        lbl_99_rodata_10, lbl_99_rodata_10, lbl_99_rodata_10), accesser);
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(energy) + 0x3c) =
        soValueAccesser::getConstantFloat(accesser, 0xfbf, 0);
    Vec2f brake(lbl_99_rodata_20, lbl_99_rodata_20);
    fn_99_AA80(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 0x18), &brake);
    Vec2f limit(soValueAccesser::getConstantFloat(accesser, 0xbbc, 0), lbl_99_rodata_10);
    fn_99_AA80(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 0x20), &limit);
    Vec2f stable(soValueAccesser::getConstantFloat(accesser, 0xfbe, 0), lbl_99_rodata_10);
    fn_99_AA80(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 0x28), &stable);
    reinterpret_cast<LuigiGroundResetEnable*>(reinterpret_cast<unsigned char*>(energy) + 5)->enabled = 1;
}
