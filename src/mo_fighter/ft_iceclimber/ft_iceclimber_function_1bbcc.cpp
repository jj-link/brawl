#include <types.h>
#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#include <mt/mt_vector.h>
#pragma force_active on

namespace {
class IceClimberTeamValue {
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual int getValue();
};
class IceClimberTeamModule {
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual IceClimberTeamValue* getValue();
};
}

extern "C" {
void fn_105_CBC8(Vec3f*, const Vec3f*, const Vec3f*);
void fn_105_2096C(void*, int, int, f32, void*, const Vec3f*, const Vec3f*, f32, f32);
}

extern "C" int fn_105_1BBCC(void* self, soModuleAccesser* accesser) {
    f32 lr;
    f32 f30 = accesser->m_enumerationStart->m_workManageModule->getFloat(0x11000001);
    f32 f29 = accesser->m_enumerationStart->m_workManageModule->getFloat(0x11000002);

    Vec3f base = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(9, false);
    Vec3f pos7 = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(7, false);
    Vec3f diff1, diff2, diff3;
    fn_105_CBC8(&diff1, &pos7, &base);
    Vec3f pos8 = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(8, false);
    fn_105_CBC8(&diff2, &pos8, &base);
    Vec3f pos5 = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(5, false);
    fn_105_CBC8(&diff3, &pos5, &base);

    IceClimberTeamModule* team = static_cast<IceClimberTeamModule*>(accesser->m_enumerationStart->m_teamModule);
    int taskId = accesser->m_stageObject->m_taskId;
    lr = accesser->m_enumerationStart->m_postureModule->getLr();
    int value = team->getValue()->getValue();
    fn_105_2096C(self, taskId, value, lr, &diff1, &diff2, &diff3, f30, f29);
    return 1;
}
