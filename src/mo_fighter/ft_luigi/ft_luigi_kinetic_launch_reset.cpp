#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" {
extern const char lbl_99_data_6244[], lbl_99_data_639C[], lbl_99_data_171C[];
extern const float lbl_99_rodata_10;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec2f* fn_99_AA80(Vec2f*, const Vec2f*);
void fn_27_15FBC8(int);
}

inline float scaleLaunchCharge(int charge, float slope) {
    return charge * slope;
}

extern "C" void fn_99_BFB0(void*, int, const void*, soModuleAccesser* accesser) {
    fn_27_15FBC8(10);
    soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(3), 0,
        lbl_99_data_6244, lbl_99_data_171C, 1));
    float horizontal, vertical;
    if (accesser->getWorkManageModule().isFlag(0x22000012) == true) {
        horizontal = soValueAccesser::getConstantFloat(accesser, 0xfb9, 0);
        vertical = soValueAccesser::getConstantFloat(accesser, 0xfba, 0);
    } else {
        soWorkManageModule* work = &accesser->getWorkManageModule();
        float slope = soValueAccesser::getConstantFloat(accesser, 0xfb1, 0);
        slope = scaleLaunchCharge(work->getInt(0x20000000), slope);
        horizontal = soValueAccesser::getConstantFloat(accesser, 0xfb0, 0);
        horizontal += slope;
        work = &accesser->getWorkManageModule();
        slope = soValueAccesser::getConstantFloat(accesser, 0xfb3, 0);
        slope = scaleLaunchCharge(work->getInt(0x20000000), slope);
        vertical = soValueAccesser::getConstantFloat(accesser, 0xfb2, 0);
        vertical += slope;
    }
    Vec2f speed(horizontal * accesser->getPostureModule().getLr(), lbl_99_rodata_10);
    fn_99_AA80(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(stop) + 8), &speed);
    Vec2f limit(lbl_99_rodata_10, lbl_99_rodata_10);
    fn_99_AA80(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(stop) + 0x20), &limit);
    soKineticEnergy* gravity = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(1), 0,
        lbl_99_data_639C, lbl_99_data_171C, 1));
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(gravity) + 0x0c) = vertical;
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(gravity) + 0x10) =
        -soValueAccesser::getConstantFloat(accesser, 0xfb4, 0);
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(gravity) + 0x14) =
        soValueAccesser::getConstantFloat(accesser, 0xfb5, 0);
}
