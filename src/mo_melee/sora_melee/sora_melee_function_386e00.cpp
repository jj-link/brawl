#include <types.h>
#include <so/so_module_accesser.h>
#include <so/motion/so_motion_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, u32 id, u32 index);
extern "C" int randi__Fl(long);
extern "C" const float lbl_27_rodata_7C58[];

extern "C" void fn_27_386E00(void*, soModuleAccesser* accesser) {
    const float* c = lbl_27_rodata_7C58;
    soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
    float limit = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xFA5, 0);
    float v;

    if (work->getFloat(0x1100001E) < limit) {
        if (c[0] == accesser->m_enumerationStart->m_workManageModule->getFloat(0x1100001F)) {
            v = c[0];
        } else {
            v = c[1];
        }
    } else {
        if (c[0] == accesser->m_enumerationStart->m_workManageModule->getFloat(0x1100001F)) {
            if (randi__Fl(3) < 2) {
                v = c[0];
            } else {
                v = c[1];
            }
        } else {
            if (randi__Fl(3) < 2) {
                v = c[1];
            } else {
                v = c[0];
            }
        }
    }

    if (c[1] == v) {
        soMotionChangeParam p;
        p.m_kind = 0x1D4;
        p.m_frame = c[2];
        p.m_rate = c[1];
        p._12 = 0;
        p._13 = 0;
        p._14 = 0;
        p._15 = 0;
        accesser->m_enumerationStart->m_motionModule->changeMotionRequest(&p);
    } else {
        soMotionChangeParam p;
        p.m_kind = 0x1D5;
        p.m_frame = c[2];
        p.m_rate = c[1];
        p._12 = 0;
        p._13 = 0;
        p._14 = 0;
        p._15 = 0;
        accesser->m_enumerationStart->m_motionModule->changeMotionRequest(&p);
    }
}
