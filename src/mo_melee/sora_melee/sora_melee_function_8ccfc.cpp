#include <StaticAssert.h>
#include <mt/mt_vector.h>
#include <so/so_external_value_accesser.h>
#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#include <so/work/so_work_manage_module_impl.h>
#include <types.h>
#pragma force_active on

bool soExternalValueAccesser::getWorkFlag(StageObject* stageObject, u32 flag) {
    return stageObject->m_moduleAccesser->getWorkManageModule().isFlag(flag);
}
