#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_118_rodata_0[];
float fn_118_8F8C(float, float, float);
}

extern "C" float fn_118_960C(soModuleAccesser* accesser) {
    const float* constants = lbl_118_rodata_0;
    ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(0x21));
    const float* p = *reinterpret_cast<const float**>(reinterpret_cast<char*>(data) + 0x84);
    float damage = accesser->getDamageModule().getDamage(0);
    float value;
    if (damage <= p[3]) {
        value = p[0] + (constants[1] - p[0]) * fn_118_8F8C((damage - p[2]) / (p[3] - p[2]), constants[3], constants[1]);
    } else {
        value = constants[1] + (p[1] - constants[1]) * fn_118_8F8C((damage - p[3]) / (p[4] - p[3]), constants[3], constants[1]);
    }
    value /= constants[1] + constants[5] * fn_118_8F8C(soValueAccesser::getConstantFloat(accesser, 0xdb2, 0), constants[4], constants[1]);
    return fn_118_8F8C(p[5] * value, p[7], p[6]);
}