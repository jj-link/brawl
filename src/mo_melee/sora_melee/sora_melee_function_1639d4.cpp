#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/posture/so_posture_module_simple.h>
#include <so/work/so_work_manage_module_impl.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
double fn_80400B44(double, double);
extern const float lbl_27_rodata_1FC0;
}

extern "C" void fn_27_1639D4(int, int, int, soModuleAccesser* accesser) {
    float lr = accesser->getPostureModule().getLr();
    float a = soValueAccesser::getConstantFloat(accesser, 0xC0A, 0);
    a *= lr;
    float b = soValueAccesser::getConstantFloat(accesser, 0xC99, 0);
    b *= a;

    Vec2f v1;
    Vec3f z1;
    z1.m_x = lbl_27_rodata_1FC0;
    z1.m_y = lbl_27_rodata_1FC0;
    z1.m_z = lbl_27_rodata_1FC0;
    v1.m_x = b;
    v1.m_y = lbl_27_rodata_1FC0;
    fn_27_89D08(2, accesser, 3, &v1, &z1);

    float scale = soValueAccesser::getConstantFloat(accesser, 0xC0B, 0);
    if (accesser->getWorkManageModule().getInt(0x10000003) - 1 > 0) {
        float base = soValueAccesser::getConstantFloat(accesser, 0xC98, 0);
        scale *= (float)fn_80400B44(base, (float)(accesser->getWorkManageModule().getInt(0x10000003) - 1));
    }

    Vec2f v2;
    Vec3f z2;
    v2.m_y = scale;
    z2.m_x = lbl_27_rodata_1FC0;
    z2.m_y = lbl_27_rodata_1FC0;
    z2.m_z = lbl_27_rodata_1FC0;
    v2.m_x = lbl_27_rodata_1FC0;
    fn_27_89D08(1, accesser, 0, &v2, &z2);
}
