#include <ft/fighter.h>
#include <ft/ft_owner.h>
#include <ft/ft_common_data_accesser.h>
#include <so/so_value_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
extern "C" {
extern const char lbl_118_data_19D4[], lbl_118_data_2250[];
extern const float lbl_118_rodata_0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_27_1119A0(ftOwner*);
float fn_118_8F8C(float, float, float);
}
extern "C" float fn_118_973C(soModuleAccesser* accesser) {
    const float* constants = lbl_118_rodata_0;
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(accesser->m_stageObject, 0x3c, lbl_118_data_19D4, lbl_118_data_2250, 1));
    const float* p = *reinterpret_cast<const float**>(reinterpret_cast<char*>(g_ftCommonDataAccesser.getData(static_cast<ftKind>(0x21))) + 0x98);
    float maximum = fn_27_1119A0(fighter->getOwner());
    float damage = fighter->getOwner()->getHitPoint();
    float ratio;
    if ((float)(double)nw4r::math::FAbs(maximum) > constants[6])
        ratio = damage / maximum;
    else
        ratio = constants[1];
    float value = fn_118_8F8C(constants[7] * ratio, constants[3], constants[7]);
    float result;
    if (maximum <= constants[1]) {
        result = p[1];
    } else if (value <= p[3]) {
        result = p[1] - (p[1] - constants[1]) * fn_118_8F8C((value - p[4]) / (p[3] - p[4]), constants[3], constants[1]);
    } else {
        result = constants[1] - (constants[1] - p[0]) * fn_118_8F8C((value - p[3]) / (p[2] - p[3]), constants[3], constants[1]);
    }
    result /= constants[1] + constants[5] * fn_118_8F8C(soValueAccesser::getConstantFloat(accesser, 0xdb2, 0), constants[4], constants[1]);
    return fn_118_8F8C(result, p[6], p[5]);
}