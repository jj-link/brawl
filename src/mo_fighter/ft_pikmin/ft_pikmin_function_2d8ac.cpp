#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <math.h>
#pragma force_active on

extern "C" {
extern const float lbl_113_rodata_198;
extern const float lbl_113_rodata_19C;
extern const float lbl_113_rodata_1B0;
void fn_8003DE70(Vec3f*);
}

extern "C" Vec3f fn_113_2D8AC(void*, soModuleAccesser* accesser) {
    float q = soValueAccesser::getConstantFloat(accesser, 0xFA2, 0) * (float)accesser->getWorkManageModule().getInt(0x20000000);
    float s = accesser->getPostureModule().getScale();
    q *= s;
    float ang = soValueAccesser::getConstantFloat(accesser, 0xFA1, 0);
    Vec3f v(q * cosf(lbl_113_rodata_198 * ang), q * sinf(lbl_113_rodata_198 * ang), lbl_113_rodata_19C);

    int sign;
    if (accesser->getLinkModule().getParentLr(3) < lbl_113_rodata_19C) {
        sign = -1;
    } else {
        sign = 1;
    }

    v.m_x = v.m_x * (float)sign;
    float t = (float)accesser->getWorkManageModule().getInt(0x10000007);
    float lim = s * (t * lbl_113_rodata_1B0);

    if (q >= lim) {
        if (q > lim) {
            fn_8003DE70(&v);
            v.m_x = v.m_x * lim;
            v.m_y = v.m_y * lim;
            v.m_z = v.m_z * lim;
        }
        accesser->getWorkManageModule().onFlag(0x22000001);
    }
    return v;
}
