#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <cmath>
#pragma force_active on

extern "C" {
extern const float lbl_115_rodata_30;
extern const char lbl_115_data_7524[], lbl_115_data_7444[], lbl_115_data_2760[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_115_8EF8(Vec3f*, float, float, float);
}

struct DiddyKineticEnable { unsigned char enabled : 1; };

static inline Vec3f* initializeRotation(const Vec3f& rotation, float x, float y, float z) {
    return fn_115_8EF8(const_cast<Vec3f*>(&rotation), x, y, z);
}

extern "C" void fn_115_DA80(void*, soModuleAccesser* accesser) {
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x11B: {
        float attack = soValueAccesser::getConstantFloat(accesser, 0xfa9, 0);
        float speedY = soValueAccesser::getConstantFloat(accesser, 0xfaa, 0);
        float lr = accesser->getPostureModule().getLr();
        if (accesser->getWorkManageModule().isFlag(0x22000011)) {
            attack = soValueAccesser::getConstantFloat(accesser, 0xfab, 0);
        }
        soKineticEnergy* gravity = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(1), 0,
            lbl_115_data_7524, lbl_115_data_2760, 1));
        Vec2f gravitySpeed;
        gravitySpeed.m_x = lbl_115_rodata_30;
        gravitySpeed.m_y = speedY;
        gravity->resetEnergy(0, &gravitySpeed, initializeRotation(Vec3f(),
            lbl_115_rodata_30, lbl_115_rodata_30, lbl_115_rodata_30), accesser);
        reinterpret_cast<DiddyKineticEnable*>(reinterpret_cast<unsigned char*>(gravity) + 5)->enabled = 1;
        soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(3), 0,
            lbl_115_data_7444, lbl_115_data_2760, 1));
        Vec2f stopSpeed;
        stopSpeed.m_x = attack * lr;
        stopSpeed.m_y = lbl_115_rodata_30;
        stop->resetEnergy(6, &stopSpeed, initializeRotation(Vec3f(),
            lbl_115_rodata_30, lbl_115_rodata_30, lbl_115_rodata_30), accesser);
        reinterpret_cast<DiddyKineticEnable*>(reinterpret_cast<unsigned char*>(stop) + 5)->enabled = 1;
        break;
    }
    }
}
