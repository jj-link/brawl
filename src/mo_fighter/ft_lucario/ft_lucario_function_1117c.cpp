#include <nw4r/math/math_arithmetic.h>
#include <nw4r/ut/ut_algorithm.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_118_rodata_98[];

float fn_118_8F8C(float, float, float);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, u32, u32);

void fn_118_1117C(soModuleAccesser* accesser) {
    const float* const constants = lbl_118_rodata_98;
    const soModuleEnumeration& modules = *accesser->m_enumerationStart;
    soWorkManageModule* work = modules.m_workManageModule;
    soPostureModule* posture = modules.m_postureModule;
    soControllerModule& controller = *modules.m_controllerModule;

    float lower = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xC2D, 0);
    float upper = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xC36, 0);

    float angle = controller.getStickX();
    float sign;
    if (angle >= constants[0]) {
        sign = constants[3];
    } else {
        sign = constants[6];
        float magnitude = static_cast<float>(
            static_cast<double>(nw4r::ut::Abs(angle)));
        angle = magnitude;
    }

    float scale = sign * fn_118_8F8C(
        (angle - lower) / (upper - lower),
        constants[0],
        constants[3]);

    float multiplier =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xFCC, 0);
    float limit =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xFCB, 0);

    float value = work->getFloat(0x21000004);
    float result = fn_118_8F8C(
        value + multiplier * scale *
                    (constants[6] * posture->getLr()),
        -limit, limit);
    work->setFloat(result, 0x21000004);

    if (constants[0] != scale &&
        work->getInt(0x20000001) > 3) {
        work->setInt(3, 0x20000001);
    }
}
}
