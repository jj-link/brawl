#include <so/so_value_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
extern "C" const float lbl_27_rodata_7C68[];
extern "C" int fn_27_3872F0(void*, void*, int, soModuleAccesser* a) {
    const float* c = lbl_27_rodata_7C68;
    if (a->m_enumerationStart->m_workManageModule->getInt(0x10000045) <= 0 &&
        a->m_enumerationStart->m_workManageModule->isFlag(0x12000040) &&
        a->m_enumerationStart->m_workManageModule->isFlag(0x12000041) != 1) {
        float v = (float)(double)nw4r::math::FAbs(a->m_enumerationStart->m_workManageModule->getFloat(0x1100001b));
        if (v > a->m_enumerationStart->m_workManageModule->getFloat(0x11000020)) {
            float dir = a->m_enumerationStart->m_workManageModule->getFloat(0x11000016) < c[2] ? c[0] : c[1];
            float side = a->m_enumerationStart->m_workManageModule->getFloat(0x1100001f);
            if (dir == (c[0] == side ? c[0] : c[1])) {
                v = (float)(double)nw4r::math::FAbs(a->m_enumerationStart->m_workManageModule->getFloat(0x1100001e));
                if (v < soValueAccesser::getConstantFloat(a, 0xfa5, 0)) return 0;
                if (a->m_enumerationStart->m_groundModule->isNearCliff(dir, soValueAccesser::getConstantFloat(a, 0xfa5, 0), 0) == 1) return 0;
            }
            return 1;
        }
    }
    return 0;
}