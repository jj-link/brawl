#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <nw4r/ut/ut_algorithm.h>
#include <math.h>
#pragma force_active on

float randf();

extern "C" {
extern const float lbl_116_rodata_C0[];
extern const char lbl_116_data_7710[], lbl_116_data_2260[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float rsqrtf__Ff(float);
}

extern "C" void fn_116_23BA8(void* self, soModuleAccesser* accesser) {
    const float* constants = lbl_116_rodata_C0;

    int count = accesser->getWorkManageModule().getInt(0x10000005);
    count++;
    if (count > soValueAccesser::getConstantInt(accesser, 0x5DC1, 0)) {
        float base = accesser->getWorkManageModule().getFloat(0x11000003);
        float range = soValueAccesser::getConstantFloat(accesser, 0xFA3, 0);
        float value = base + (constants[0] * range * randf() - range);
        accesser->getWorkManageModule().setFloat(value, 0x11000004);
        count = 0;
    }
    accesser->getWorkManageModule().setInt(count, 0x10000005);

    float lr = accesser->getWorkManageModule().getFloat(0x11000001);
    float other = accesser->getWorkManageModule().getFloat(0x11000002);
    accesser->getWorkManageModule().setFloat(lr + other, 0x11000001);
    float angle = accesser->getWorkManageModule().getFloat(0x11000004);
    accesser->getWorkManageModule().getFloat(0x11000003);
    accesser->getWorkManageModule().setFloat(angle, 0x11000003);

    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(0), 0, lbl_116_data_7710, lbl_116_data_2260, 1));
    float lenSq = energy->getSpeed().lengthSq();
    float mag;
    if (static_cast<float>(static_cast<double>(nw4r::ut::Abs(lenSq))) <= constants[2]) {
        mag = constants[1];
    } else {
        mag = lenSq * rsqrtf__Ff(lenSq);
    }
    float facing = accesser->getPostureModule().getLr();
    Vec2f velocity(facing * (mag * static_cast<float>(cos(constants[3] * angle))),
                   mag * static_cast<float>(sin(constants[3] * angle)));
    *reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 8) = velocity;
    reinterpret_cast<unsigned char*>(energy)[5] |= 0x80;
}
