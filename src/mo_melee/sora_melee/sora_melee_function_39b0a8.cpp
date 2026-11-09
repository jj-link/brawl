#include <ft/fighter.h>
#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
void fn_27_39EA1C(void*, unsigned int, int, int, int, float, double);
extern const char lbl_27_data_69C0[];
extern const char lbl_27_data_248[];
}

extern "C" bool fn_27_39B0A8(void*, void* arg2, soModuleAccesser* acc) {
    Fighter* fighter = static_cast<Fighter*>(
        __dynamic_cast(acc->m_stageObject, 0x3c, lbl_27_data_69C0,
                       lbl_27_data_248, 1));
    int value = 0;
    soWorkManageModule* work = acc->m_enumerationStart->m_workManageModule;
    if (&value != 0)
        value = work->getInt(0x10000040);
    if (!work->isFlag(0x1200003d))
        value = 0;
    const double factor =
        acc->m_enumerationStart->m_workManageModule->getFloat(0x11000013);
    float rounded = factor;
    int kind;
    soPostureModule* posture;
    unsigned int id;
    posture = acc->m_enumerationStart->m_postureModule;
    id = fighter->m_taskId;
    kind = fighter->getFtKind();
    int owner = fn_27_111364(fighter->getOwner());
    float facing = posture->getLr();
    fn_27_39EA1C(arg2, id, owner, value, kind, facing,
                 factor);
    return true;
}
