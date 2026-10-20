#include <types.h>
#include <so/stageobject.h>
#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" s32 fn_41_A884(void);

extern "C" s32 fn_41_3A350(StageObject* self) {
    s32 result = 0;
    u32 val = fn_41_A884();
    if (val == 1) result = 1;
    if (self->m_moduleAccesser->getWorkManageModule().isFlag(0x12000006) == 1) result = 1;
    return result;
}
