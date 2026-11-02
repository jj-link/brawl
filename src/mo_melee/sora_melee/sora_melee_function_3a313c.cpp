#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#pragma force_active on

namespace {
class TeamValue {
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual int getValue();
};

class TeamModule {
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual TeamValue* getValue();
};
}

extern "C" {
extern unsigned char lbl_27_bss_7B0C[];
extern const float lbl_27_rodata_7E98;
int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
float fn_27_192278(void*, unsigned long);
int fn_27_1922CC(void*, unsigned long);
void fn_27_3A4C60(void*, unsigned int, void*, int, Vec3f*, int, int, float, float);
}

extern "C" int fn_27_3A313C(void* unused, void* p1, soModuleAccesser* accesser, void* p3) {
    TeamModule* team;
    int r30v;
    unsigned int taskId;
    soWorkManageModule* work;
    int timer;
    int var25;

    fn_27_30FACC(lbl_27_bss_7B0C, 0, accesser->getStatusModule().getStatusKind(), accesser, 1);
    float f30 = accesser->getPostureModule().getLr();
    timer = fn_27_1922CC(accesser, 0x5dc0);

    Vec3f pos;
    if (accesser->getSituationModule().getKind() == 2) {
        Vec3f offset;
        offset.m_x = lbl_27_rodata_7E98;
        offset.m_y = fn_27_192278(accesser, 0xfaa);
        offset.m_z = fn_27_192278(accesser, 0xfa9);
        pos = accesser->getModelModule().getNodeGlobalPosition(timer, &offset, false, false);
    } else {
        Vec3f offset;
        offset.m_x = lbl_27_rodata_7E98;
        offset.m_y = fn_27_192278(accesser, 0xfa8);
        offset.m_z = fn_27_192278(accesser, 0xfa7);
        pos = accesser->getModelModule().getNodeGlobalPosition(timer, &offset, false, false);
    }

    var25 = 0;
    soWorkManageModule& work1 = accesser->getWorkManageModule();
    float threshold = fn_27_192278(accesser, 0xfa6);
    if (work1.getFloat(0x11000013) >= threshold) {
        var25 = 1;
    }

    const soModuleEnumeration* enumeration = accesser->m_enumerationStart;
    work = enumeration->m_workManageModule;
    team = static_cast<TeamModule*>(enumeration->m_teamModule);
    taskId = accesser->m_stageObject->m_taskId;
    r30v = work->getInt(0x10000044);
    float f31 = work->getFloat(0x21000004);
    int teamVal = team->getValue()->getValue();
    fn_27_3A4C60(p1, taskId, p3, teamVal, &pos, var25, r30v, f30, f31);
    return 0;
}
