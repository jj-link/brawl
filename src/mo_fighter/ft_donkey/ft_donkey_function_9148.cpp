#include <ft/ft_common_data_accesser.h>
#include <ft/fighter.h>
#include <so/so_module_accesser.h>
#include <math.h>
#pragma force_active on

extern "C" {
extern const char lbl_92_data_1A98[], lbl_92_data_2314[];
extern const float lbl_92_rodata_8;
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
void fn_92_14E80(void* object, unsigned int taskId, int ownerId, const Vec3f* position, float f1, float f2, float f3, float f4, bool flag);
}

extern "C" int fn_92_9148(void* object, soModuleAccesser* accesser) {
    bool flag;
    unsigned int taskId;
    soWorkManageModule* work;
    Fighter* fighter;
    fighter = static_cast<Fighter*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_92_data_1A98, lbl_92_data_2314, static_cast<short>(1)));
    Vec3f position = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(5, false);
    position.m_z = lbl_92_rodata_8;
    work = accesser->m_enumerationStart->m_workManageModule;
    taskId = fighter->m_taskId;
    flag = work->isFlag(0x22000011);
    fn_92_14E80(object, taskId, fn_27_111364(fighter->getOwner()), &position,
                work->getFloat(0x21000005), work->getFloat(0x21000006),
                work->getFloat(0x21000007), work->getFloat(0x21000008), flag);
    return 0;
}
