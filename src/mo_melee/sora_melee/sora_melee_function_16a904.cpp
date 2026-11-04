#pragma force_active on
#pragma fp_contract off

#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <so/motion/so_motion_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/collision/so_collision_shield_module_impl.h>
#include <mt/mt_vector.h>
#include <types.h>

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern char lbl_27_data_13690[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_2110;
extern const float lbl_27_rodata_2114;

class Holder {
public:
    virtual void s0();
    virtual void s1();
    virtual void notify(soModuleAccesser* acc);
};

struct Arg0 {
    char pad[4];
    Holder* holder;
};

extern "C" void fn_27_16A904(Arg0* arg0, soModuleAccesser* arg1) {
    arg1->m_enumerationStart->m_collisionShieldModule->setStatus(0, 1, 0);
    soWorkManageModule* work = arg1->m_enumerationStart->m_workManageModule;
    float f31 = lbl_27_rodata_2110 - soValueAccesser::getConstantFloat(arg1, 0xcb1, 0);
    float g = work->getFloat(0x21000008);
    f31 = g * f31;
    float h = soValueAccesser::getConstantFloat(arg1, 0xcaa, 0);
    f31 = h * f31;
    float k = soValueAccesser::getConstantFloat(arg1, 0xcab, 0);
    f31 = k + f31;
    int n = (int)f31;
    arg1->m_enumerationStart->m_workManageModule->setInt(n, 0x20000005);
    float f30 = lbl_27_rodata_2110;
    if (arg1->m_enumerationStart->m_motionModule->isAnimResFile(0x42) == 1) {
        f30 = arg1->m_enumerationStart->m_motionModule->getEndFrame(0x42) / (float)n;
    }
    soMotionChangeParam param;
    param.m_kind = 0x42;
    param.m_frame = lbl_27_rodata_2114;
    param.m_rate = f30;
    param._12 = 0;
    param._13 = 0;
    param._14 = 0;
    param._15 = 0;
    arg1->m_enumerationStart->m_motionModule->changeMotionRequest(&param);
    float speed = f31 * soValueAccesser::getConstantFloat(arg1, 0xcac, 0);
    if (arg1->m_enumerationStart->m_workManageModule->getInt(0x20000001) > 0) {
        speed = speed * soValueAccesser::getConstantFloat(arg1, 0xcb3, 0);
    }
    if (speed > soValueAccesser::getConstantFloat(arg1, 0xcad, 0)) {
        speed = soValueAccesser::getConstantFloat(arg1, 0xcad, 0);
    }
    soKineticEnergy* energy = arg1->m_enumerationStart->m_kineticModule->getEnergy(4);
    soKineticEnergy* e = (soKineticEnergy*)__dynamic_cast(energy, 0, lbl_27_data_13690, lbl_27_data_CDF8, 1);
    Vec2f v2;
    Vec3f v3;
    v2.m_x = speed * -arg1->m_enumerationStart->m_workManageModule->getFloat(0x21000009);
    v2.m_y = lbl_27_rodata_2114;
    v3.m_x = lbl_27_rodata_2114;
    v3.m_y = lbl_27_rodata_2114;
    v3.m_z = lbl_27_rodata_2114;
    e->resetEnergy(0xB, &v2, &v3, arg1);
    ((unsigned char*)e)[5] |= 0x80;
    arg0->holder->notify(arg1);
}
