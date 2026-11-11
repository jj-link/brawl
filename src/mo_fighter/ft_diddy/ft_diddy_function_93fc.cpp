#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/stageobject.h>
#pragma force_active on

namespace {
class DiddyPostureView {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual float slot2C();
};

class DiddyTeamValue {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual int slot10();
};

class DiddyTeamModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual DiddyTeamValue* slot10();
};
}

extern "C" {
extern const float lbl_115_rodata_C;
void fn_115_1B518(void* arg0, u32 taskId, int team, float f, Vec3f* pos);
}

extern "C" int fn_115_93FC(void* arg0, soModuleAccesser* accesser) {
    Vec3f offset;
    offset.m_x = lbl_115_rodata_C;
    offset.m_y = soValueAccesser::getConstantFloat(accesser, 0xfd4, 0);
    DiddyPostureView* posture = reinterpret_cast<DiddyPostureView*>(accesser->m_enumerationStart->m_postureModule);
    float lr = posture->slot2C();
    float scale = soValueAccesser::getConstantFloat(accesser, 0xfd3, 0);
    scale *= lr;
    offset.m_z = scale;
    Vec3f pos = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(0, &offset, true, false);
    u32 taskId = accesser->m_stageObject->m_taskId;
    DiddyTeamModule* team = reinterpret_cast<DiddyTeamModule*>(accesser->m_enumerationStart->m_teamModule);
    int teamValue = team->slot10()->slot10();
    fn_115_1B518(arg0, taskId, teamValue, lbl_115_rodata_C, &pos);
    return 0;
}
