#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>

#pragma force_active on

extern "C" {
void* __memcpy(void*, const void*, unsigned long);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
void fn_8003DC64(Vec2f*, float*, float, float);
double fn_80400B44(double, double);
float fn_27_194AD4(soModuleAccesser*);
extern const float lbl_27_rodata_1FC0;
extern const float lbl_27_rodata_1FD0;
}

extern "C" void fn_27_160CE8(int, int, const Vec2f* input, soModuleAccesser* accesser) {
    Vec3f z2;
    Vec2f v;
    __memcpy(&v, input, sizeof(v));
    int flag = 0;
    float t;

    if (accesser->getWorkManageModule().isFlag(0x22000007)) {
        t = soValueAccesser::getConstantFloat(accesser, 0xBC4, 0);
        t *= accesser->getControllerModule().getStickX();
        v.m_x = v.m_x * soValueAccesser::getConstantFloat(accesser, 0xBC6, 0);
        v.m_x += t;
        float lim = soValueAccesser::getConstantFloat(accesser, 0xBC7, 0);
        if ((float)(double)nw4r::math::FAbs(v.m_x) > lim) {
            v.m_x = (v.m_x < lbl_27_rodata_1FC0) ? -lim : lim;
        }
        if (accesser->getWorkManageModule().isFlag(0x22000006)) {
            v.m_y = soValueAccesser::getConstantFloat(accesser, 0xBCC, 0);
        } else {
            v.m_y = soValueAccesser::getConstantFloat(accesser, 0xBCB, 0);
        }
        v.m_y *= accesser->getWorkManageModule().getFloat(0x21000004);
        int count = accesser->getWorkManageModule().getInt(0x10000005);
        if (count > 1) {
            v.m_y *= (float)fn_80400B44(
                soValueAccesser::getConstantFloat(accesser, 0xC9A, 0),
                (float)(count - 1));
        }
    } else if (accesser->getWorkManageModule().isFlag(0x22000008)) {
        v.m_x = soValueAccesser::getConstantFloat(accesser, 0xBC7, 0) *
                accesser->getControllerModule().getStickX();
        v.m_y = soValueAccesser::getConstantFloat(accesser, 0xBC5, 0) *
                soValueAccesser::getConstantFloat(accesser, 0xD18, 0);
    } else if (accesser->getWorkManageModule().isFlag(0x2200000B)) {
        t = soValueAccesser::getConstantFloat(accesser, 0xBC4, 0);
        t *= accesser->getControllerModule().getStickX();
        v.m_x = v.m_x * soValueAccesser::getConstantFloat(accesser, 0xBC6, 0);
        v.m_x += t;
        float lim = soValueAccesser::getConstantFloat(accesser, 0xBC7, 0);
        if ((float)(double)nw4r::math::FAbs(v.m_x) > lim) {
            v.m_x = (v.m_x < lbl_27_rodata_1FC0) ? -lim : lim;
        }
        v.m_y = soValueAccesser::getConstantFloat(accesser, 0xBC5, 0);
        int count = accesser->getWorkManageModule().getInt(0x10000013);
        if (count > 1) {
            v.m_y *= (float)fn_80400B44(
                soValueAccesser::getConstantFloat(accesser, 0xD1D, 0),
                (float)(count - 1));
        }
    } else if (accesser->getWorkManageModule().isFlag(0x2200000C)) {
        float base = accesser->getWorkManageModule().getFloat(0x21000004);
        float f30 = soValueAccesser::getConstantFloat(accesser, 0xC7D, 0);
        float f31 = soValueAccesser::getConstantFloat(accesser, 0xBCF, 0);
        float f29 = base + f30 * (f31 - soValueAccesser::getConstantFloat(accesser, 0xCD8, 0));
        float angle = lbl_27_rodata_1FD0 * accesser->getWorkManageModule().getFloat(0x21000005);
        Vec2f a;
        a.m_x = lbl_27_rodata_1FC0;
        a.m_y = f29;
        fn_8003DC64(&a, &v.m_x, angle, lbl_27_rodata_1FC0);
        flag = 1;
    } else {
        t = soValueAccesser::getConstantFloat(accesser, 0xBC4, 0);
        v.m_x = v.m_x * soValueAccesser::getConstantFloat(accesser, 0xBC6, 0) +
                t * accesser->getControllerModule().getStickX();
        float lim = soValueAccesser::getConstantFloat(accesser, 0xBC7, 0);
        if ((float)(double)nw4r::math::FAbs(v.m_x) > lim) {
            v.m_x = (v.m_x < lbl_27_rodata_1FC0) ? -lim : lim;
        }
        if (accesser->getWorkManageModule().isFlag(0x2200000A)) {
            v.m_y = v.m_y * soValueAccesser::getConstantFloat(accesser, 0xC46, 0) +
                    soValueAccesser::getConstantFloat(accesser, 0xBC5, 0) *
                    soValueAccesser::getConstantFloat(accesser, 0xD7E, 0);
        } else if (accesser->getWorkManageModule().isFlag(0x22000006)) {
            v.m_y = v.m_y * soValueAccesser::getConstantFloat(accesser, 0xC46, 0) +
                    soValueAccesser::getConstantFloat(accesser, 0xBC8, 0) *
                    fn_27_194AD4(accesser);
        } else {
            v.m_y = v.m_y * soValueAccesser::getConstantFloat(accesser, 0xC46, 0) +
                    soValueAccesser::getConstantFloat(accesser, 0xBC5, 0) *
                    fn_27_194AD4(accesser);
        }
    }

    Vec2f m;
    Vec2f g;
    Vec3f z1;
    g.m_y = v.m_y;
    z1.m_x = lbl_27_rodata_1FC0;
    z1.m_y = lbl_27_rodata_1FC0;
    z1.m_z = lbl_27_rodata_1FC0;
    g.m_x = lbl_27_rodata_1FC0;
    fn_27_89D08(1, accesser, 0, &g, &z1);

    float vx = v.m_x;
    z2.m_x = lbl_27_rodata_1FC0;
    z2.m_y = lbl_27_rodata_1FC0;
    z2.m_z = lbl_27_rodata_1FC0;
    m.m_x = vx;
    m.m_y = lbl_27_rodata_1FC0;
    fn_27_89D08(2, accesser, flag, &m, &z2);
}
