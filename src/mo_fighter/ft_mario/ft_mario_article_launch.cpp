#include <so/stageobject.h>
#include <so/so_value_accesser.h>

class MarioArticleTeamValue {
public:
    virtual void reserved0();
    virtual void reserved1();
    virtual int getValue();
};
class MarioArticleTeamModule {
public:
    virtual void reserved0();
    virtual void reserved1();
    virtual MarioArticleTeamValue* getValue();
};
extern "C" {
extern const float lbl_91_rodata_38[];
float randf__Fv();
void fn_8003DE70(Vec3f*);
void fn_91_16554(void*, unsigned int, int, int, const Vec3f*, float, float, const Vec3f*);
int fn_91_13358(void* object, soModuleAccesser* accesser) {
    Vec3f offset;
    offset.m_z = lbl_91_rodata_38[2];
    offset.m_x = lbl_91_rodata_38[2];
    float random = randf__Fv() - lbl_91_rodata_38[4];
    float scale = soValueAccesser::getConstantFloat(accesser, 0xfa4, 0);
    offset.m_y = lbl_91_rodata_38[3] * (scale * random);
    Vec3f position = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(7, &offset, false, false);
    position.m_z = accesser->getGroundModule().getZ();
    Matrix matrix(true);
    accesser->getModelModule().getNodeGlobalMtx(7, &matrix, false);
    float directionY = matrix(1, 2);
    float directionX = matrix(0, 2);
    Vec3f direction;
    direction.m_x = directionX;
    direction.m_y = directionY;
    direction.m_z = lbl_91_rodata_38[2];
    fn_8003DE70(&direction);
    Vec3f directionSnapshot;
    __memcpy(&directionSnapshot, &direction, sizeof(direction));
    const soModuleEnumeration* enumeration = accesser->m_enumerationStart;
    soLinkModule* link = enumeration->m_linkModule;
    MarioArticleTeamModule* team = static_cast<MarioArticleTeamModule*>(enumeration->m_teamModule);
    unsigned int task;
    soWorkManageModule* work = enumeration->m_workManageModule;
    task = accesser->m_stageObject->m_taskId;
    fn_91_16554(object, task, work->getInt(0x10000005), team->getValue()->getValue(),
                &position, link->getParentLr(3), work->getFloat(0x11000001), &directionSnapshot);
    return 0;
}
}
