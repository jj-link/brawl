#include <so/stageobject.h>
#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on
class Object_vptr_0 {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
};
class DiddyTeamValue {
public: virtual void reserved0(); virtual void reserved1(); virtual int getValue();
};
class DiddyTeamModule {
public: virtual void reserved0(); virtual void reserved1(); virtual DiddyTeamValue* getValue();
};
extern "C" {
extern const float lbl_115_rodata_0[];
Vec3f* fn_115_8EF8(Vec3f*, float, float, float);
void fn_8003DC64(Vec2f*, float, Vec2f*);
void fn_27_368074(void*, unsigned int, unsigned int, int, float, const Vec3f*, const Vec2f*);
}
extern "C" int fn_115_9180(void* self, soModuleAccesser* accesser) {
const float* constants = lbl_115_rodata_0;
float lr = accesser->m_enumerationStart->m_postureModule->getLr();
Vec2f direction;
float speed = soValueAccesser::getConstantFloat(accesser, 0xfcd, 0);
direction.m_x = constants[3];
direction.m_y = speed;
Vec2f offset;
if (accesser->m_enumerationStart->m_workManageModule->isFlag(0x22000010)) {
offset.m_x = lr * soValueAccesser::getConstantFloat(accesser, 0xfcf, 0);
offset.m_y = soValueAccesser::getConstantFloat(accesser, 0xfd0, 0);
accesser->m_enumerationStart->m_workManageModule->offFlag(0x22000010);
} else if (accesser->m_enumerationStart->m_workManageModule->isFlag(0x22000011)) {
offset.m_x = lr * soValueAccesser::getConstantFloat(accesser, 0xfd1, 0);
offset.m_y = soValueAccesser::getConstantFloat(accesser, 0xfd2, 0);
accesser->m_enumerationStart->m_workManageModule->offFlag(0x22000011);
}
Vec3f local;
fn_115_8EF8(&local, constants[3], offset.m_y, offset.m_x);
Vec3f position = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(4, &local, true, false);
position.m_z = accesser->m_enumerationStart->m_groundModule->getZ();
float angle = accesser->m_enumerationStart->m_workManageModule->getFloat(0x21000007);
fn_8003DC64(&direction, constants[4] * (constants[9] - angle), &direction);
const soModuleEnumeration* enumeration = accesser->m_enumerationStart;
soResourceModule* resource = enumeration->m_resourceModule;
int team;
unsigned int task = accesser->m_stageObject->m_taskId;
team = static_cast<DiddyTeamModule*>(enumeration->m_teamModule)->getValue()->getValue();
unsigned int res = resource->getResourceIdAccesser()->getEtcResId();
fn_27_368074(self, task, res, team, lr, &position, &direction);
return 0;
}
