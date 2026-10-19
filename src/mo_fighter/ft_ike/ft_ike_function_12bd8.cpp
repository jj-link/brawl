#include <so/stageobject.h>
#pragma force_active on

struct IkeLaunchParam {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    unsigned short flags;
};

extern "C" {
void fn_27_1D8370(void*, const IkeLaunchParam*);
void fn_119_12DE4(IkeLaunchParam* param, int a1, int a2, bool a3, int a4, int a5, int a6, int a7,
                  int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15);
}

extern "C" void fn_119_12BD8(StageObject* object, int p4, int p5, int p6, int p7, int p8, int p9, int p10)
{
    if (p9) {
        IkeLaunchParam initialize;
        fn_119_12DE4(&initialize, p4, p5, true, p7, p6, 0, 0, 0, 2, -1, 0xffff, 0xffff, 0, 1, 0x80);
        initialize.owner = p10;
        fn_27_1D8370(object, &initialize);
        object->m_moduleAccesser->m_enumerationStart->m_statusModule->changeStatusForce(2, object->m_moduleAccesser);
        object->m_moduleAccesser->m_enumerationStart->m_workManageModule->onFlag(0x22000001);
    } else {
        IkeLaunchParam initialize;
        fn_119_12DE4(&initialize, p4, p5, false, p7, p6, 0, 0, 0, 2, -1, 0xffff, 0xffff, 0, 1, 0x80);
        initialize.owner = p10;
        fn_27_1D8370(object, &initialize);
        object->m_moduleAccesser->m_enumerationStart->m_linkModule->setModelConstraintPosOrt(3, 0, 0, 3, true);
        object->m_moduleAccesser->m_enumerationStart->m_workManageModule->offFlag(0x22000001);
        if (p8 == 0) {
            object->m_moduleAccesser->m_enumerationStart->m_statusModule->changeStatusForce(0, object->m_moduleAccesser);
        } else {
            object->m_moduleAccesser->m_enumerationStart->m_statusModule->changeStatusForce(1, object->m_moduleAccesser);
        }
    }
    object->m_moduleAccesser->m_enumerationStart->m_workManageModule->onFlag(0x12000000);
}
