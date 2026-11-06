#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" bool fn_27_195EA8(soModuleAccesser* a) {
    if (!a->m_enumerationStart->m_workManageModule->isFlag(0x12000039)) {
        float c = soValueAccesser::getConstantFloat(a, 0xce2, 0);
        float sq = a->m_enumerationStart->m_kineticModule->getEnergy(4)->getSpeed().lengthSq();
        float limit = c * c;
        if (sq > limit) {
            return false;
        }
    }
    return true;
}
