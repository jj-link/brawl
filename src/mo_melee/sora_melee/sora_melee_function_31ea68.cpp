#include <so/so_module_accesser.h>
#include <math.h>
#pragma force_active on

class TeamValue {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
};
class TeamModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual TeamValue* slot2();
};
extern "C" {
extern const float lbl_27_rodata_7540;
float fn_27_192278(void*, unsigned long);
void fn_27_323588(void*, unsigned int, int, int, const Vec3f*, bool, int, float, float, float);
}

extern "C" int fn_27_31EA68(void*, void* object, soModuleAccesser* a, unsigned int node, int arg4, int arg5) {
    if (a->m_enumerationStart->m_statusModule->getStatusKind() == 0x3c) {
        float z = fn_27_192278(a, 0xfa0);
        Vec3f offset;
        offset.m_y = fn_27_192278(a, 0xfa1);
        offset.m_z = z;
        offset.m_x = lbl_27_rodata_7540;
        Vec3f base = a->m_enumerationStart->m_modelModule->getNodeGlobalPosition(node, false);
        Vec3f pos = a->m_enumerationStart->m_modelModule->getNodeGlobalPosition(node, &offset, false, false);
        pos.m_z = lbl_27_rodata_7540;
        float lr0 = a->m_enumerationStart->m_postureModule->getLr();
        float dx = pos.m_x - base.m_x;
        float dy = pos.m_y - base.m_y;
        float x = dx * lr0;
        float angle = atan2(dy, x);
        soPostureModule* posture = a->m_enumerationStart->m_postureModule;
        TeamModule* team = (TeamModule*)a->m_enumerationStart->m_teamModule;
        unsigned int task = *(unsigned int*)((char*)a->m_stageObject + 0x28);
        fn_27_323588(object, task, arg4, team->slot2()->slot2(), &pos, true, arg5, posture->getLr(), fn_27_192278(a, 0xfa5), angle);
    } else if (a->m_enumerationStart->m_situationModule->getKind() == 2) {
        float z = fn_27_192278(a, 0xfa2);
        Vec3f offset;
        offset.m_y = fn_27_192278(a, 0xfa3);
        offset.m_z = z;
        offset.m_x = lbl_27_rodata_7540;
        Vec3f pos = a->m_enumerationStart->m_modelModule->getNodeGlobalPosition(node, &offset, false, false);
        pos.m_z = lbl_27_rodata_7540;
        soPostureModule* posture = a->m_enumerationStart->m_postureModule;
        TeamModule* team = (TeamModule*)a->m_enumerationStart->m_teamModule;
        unsigned int task = *(unsigned int*)((char*)a->m_stageObject + 0x28);
        fn_27_323588(object, task, arg4, team->slot2()->slot2(), &pos, false, arg5, posture->getLr(), fn_27_192278(a, 0xfa5), fn_27_192278(a, 0xfa4));
    } else {
        float z = fn_27_192278(a, 0xfa0);
        Vec3f offset;
        offset.m_y = fn_27_192278(a, 0xfa1);
        offset.m_z = z;
        offset.m_x = lbl_27_rodata_7540;
        Vec3f pos = a->m_enumerationStart->m_modelModule->getNodeGlobalPosition(node, &offset, false, false);
        pos.m_z = lbl_27_rodata_7540;
        soPostureModule* posture = a->m_enumerationStart->m_postureModule;
        TeamModule* team = (TeamModule*)a->m_enumerationStart->m_teamModule;
        unsigned int task = *(unsigned int*)((char*)a->m_stageObject + 0x28);
        fn_27_323588(object, task, arg4, team->slot2()->slot2(), &pos, false, arg5, posture->getLr(), fn_27_192278(a, 0xfa5), fn_27_192278(a, 0xfa4));
    }
    return 0;
}