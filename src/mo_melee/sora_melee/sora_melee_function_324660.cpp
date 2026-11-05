#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#include <mt/mt_matrix.h>
#pragma force_active on

class Class_1F90 {
public:
    virtual void fn_27_1EFD0();
    virtual void fn_27_E240();
    virtual int fn_27_E190();
    virtual void fn_27_E1A0();
    virtual void fn_27_1D2D0();
    virtual void fn_27_1D200();
    virtual void fn_27_1D240();
    virtual void fn_27_1EF00();
    virtual void fn_27_1EF7C();
    virtual void fn_27_E200();
};
class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual Class_1F90* fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
};
extern "C" {
extern const float lbl_27_rodata_7580;
float fn_27_192278(void*, unsigned long);
void fn_27_325C8C(void*, unsigned int, int, Vec3f*, int, int, float);
}
extern "C" int fn_27_324660(void*, void* a, soModuleAccesser* accesser, int b) {
    Class_1250* team;
    unsigned int taskId;
    int kind;
    Matrix matrix(true);
    Vec3f offset;
    Vec3f pos;
    if (accesser->getSituationModule().getKind() == 0) {
        offset.m_x = lbl_27_rodata_7580;
        offset.m_y = fn_27_192278(accesser, 0xfa1);
        offset.m_z = fn_27_192278(accesser, 0xfa0);
    } else {
        offset.m_x = lbl_27_rodata_7580;
        offset.m_y = fn_27_192278(accesser, 0xfa3);
        offset.m_z = fn_27_192278(accesser, 0xfa2);
    }
    accesser->getModelModule().getNodeGlobalMtx(0, &matrix, false);
    matrix.mulPos(&offset, &pos);
    pos.m_z = accesser->getGroundModule().getZ();
    kind = 3;
    if (accesser->m_stageObject->soGetSubKind() == 5) {
        kind = 14;
    }
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    team = static_cast<Class_1250*>(modules->m_teamModule);
    taskId = accesser->m_stageObject->m_taskId;
    float lr = modules->m_postureModule->getLr();
    int value = team->fn_27_140C0()->fn_27_E190();
    fn_27_325C8C(a, taskId, b, &pos, value, kind, lr);
    return 0;
}
