#include <cmath>
#pragma force_active on

struct soModuleAccesser;

extern "C" {
extern const float lbl_124_rodata_10;
extern const float lbl_124_rodata_14;

float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);

float fn_124_B860(void*, soModuleAccesser* moduleAccesser, float x) {
    float absx = __fabsf(x);
    if (absx > getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(moduleAccesser, 0xfc7, 0)) {
        absx = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(moduleAccesser, 0xfc7, 0);
    }
    absx -= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(moduleAccesser, 0xfc6, 0);
    if (absx < lbl_124_rodata_10) {
        absx = lbl_124_rodata_10;
    }
    if (x < lbl_124_rodata_10) {
        absx = -absx;
    }
    float c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(moduleAccesser, 0xfc6, 0);
    float d = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(moduleAccesser, 0xfc7, 0) - c;
    float e = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(moduleAccesser, 0xfc8, 0);
    return lbl_124_rodata_14 * (absx * e / d);
}
}
