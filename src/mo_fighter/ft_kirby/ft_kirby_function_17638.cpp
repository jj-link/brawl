#include <so/so_value_accesser.h>
#include <so/posture/so_posture_module_simple.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" {
void fn_27_165458(soModuleAccesser*, float, float, float, float, float, unsigned long, float);
extern const char lbl_96_rodata_88[];
void fn_27_164E48(soModuleAccesser*, const char*, unsigned long, float, unsigned long);

void fn_96_17638(void*, soModuleAccesser* accesser) {
    float e, d, c, b, a;
    b = accesser->m_enumerationStart->m_postureModule->getScale();
    a = soValueAccesser::getConstantFloat(accesser, 0xfa2, 0);
    a *= b;
    soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
    fn_27_165458(accesser, work->getFloat(0x21000004),
        soValueAccesser::getConstantFloat(accesser, 0xbbb, 0),
        soValueAccesser::getConstantFloat(accesser, 0xbb9, 0),
        soValueAccesser::getConstantFloat(accesser, 0xbba, 0),
        soValueAccesser::getConstantFloat(accesser, 0xc2e, 0),
        0x21000004, a);
    fn_27_164E48(accesser, lbl_96_rodata_88, 0x21000004, a, 0x21000005);
}
}
