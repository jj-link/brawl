#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

struct LuigiResetSpeed { float x, y; };
struct LuigiResetEnable { unsigned char enabled : 1; };
extern "C" {
extern const char lbl_99_data_6358[], lbl_99_data_171C[];
extern const float lbl_99_rodata_10, lbl_99_rodata_20;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_99_C610(Vec3f*, float, float, float);
Vec2f* fn_99_AA80(Vec2f*, const Vec2f*);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
}

extern "C" void fn_99_C620(void*, int, const LuigiResetSpeed* input,
                           soModuleAccesser* accesser) {
    Vec2f speed;
    __memcpy(&speed, input, sizeof(speed));
    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(2), 0,
        lbl_99_data_6358, lbl_99_data_171C, 1));
    Vec3f rotation;
    energy->resetEnergy(0x12, &speed, fn_99_C610(&rotation,
        lbl_99_rodata_10, lbl_99_rodata_10, lbl_99_rodata_10), accesser);
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(energy) + 0x3c) =
        soValueAccesser::getConstantFloat(accesser, 0xfc4, 0);
    Vec2f brake(lbl_99_rodata_20, lbl_99_rodata_20);
    fn_99_AA80(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 0x18), &brake);
    Vec2f limit(soValueAccesser::getConstantFloat(accesser, 0xbd6, 0), lbl_99_rodata_10);
    fn_99_AA80(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 0x20), &limit);
    Vec2f stable(soValueAccesser::getConstantFloat(accesser, 0xfc3, 0), lbl_99_rodata_10);
    fn_99_AA80(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 0x28), &stable);
    reinterpret_cast<LuigiResetEnable*>(reinterpret_cast<unsigned char*>(energy) + 5)->enabled = 1;
    Vec2f gravitySpeed(lbl_99_rodata_10, speed.m_y);
    Vec3f gravityRotation;
    fn_27_89D08(1, accesser, 0, &gravitySpeed, fn_99_C610(&gravityRotation,
        lbl_99_rodata_10, lbl_99_rodata_10, lbl_99_rodata_10));
}
