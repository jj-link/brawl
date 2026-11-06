#include <so/so_value_accesser.h>
#include <ft/ft_common_data_accesser.h>
#pragma force_active on
struct TaskBase { char pad[0x3c]; };
class TaskProxy : public TaskBase {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void processCamera();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void renderOpa(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void init(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
    virtual unsigned int slot40();
};
extern "C" unsigned int* fn_27_14554C(void*, unsigned int, unsigned int);
extern "C" bool fn_27_155E88(void*, soModuleAccesser* a) {
    int status = a->m_enumerationStart->m_statusModule->getStatusKind();
    unsigned int kind = ((TaskProxy*)a->m_stageObject)->slot40();
    if (!((*fn_27_14554C(&g_ftCommonDataAccesser, kind, status) >> 28) & 1))
        return false;
    if (a->m_enumerationStart->m_situationModule->getKind() == 0) {
        if (a->m_enumerationStart->m_groundModule->isPassableGround(0) == 1) {
            float threshold = soValueAccesser::getConstantFloat(a, 0xd16, 0);
            if (a->m_enumerationStart->m_controllerModule->getStickY() <= -threshold)
                return true;
        }
    }
    return false;
}