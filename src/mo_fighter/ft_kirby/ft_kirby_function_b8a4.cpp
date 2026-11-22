#include <types.h>
#include <wn/weapon.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <ft/ft_manager.h>
#include <ft/ft_common_data_accesser.h>
#pragma force_active on

struct Parameters { unsigned int words[0xb9]; };
class TeamValue {
public:
    virtual void v0();
    virtual void v1();
    virtual int getValue();
};
class TeamModule {
public:
    virtual void v0();
    virtual void v1();
    virtual TeamValue* getValue();
};
extern "C" {
extern const float lbl_96_rodata_4;
extern const float lbl_96_rodata_8;
Vec3f* fn_96_BC54(Vec3f*, float, float, float);
void fn_96_27E3C(Weapon*, int, int, int, float, const Vec3f*, float, int, int);
}
extern "C" int fn_96_B8A4(Weapon* object, soModuleAccesser* accesser) {
    soPostureModule* posture;
    ftManager* manager;
    TeamModule* team;
    soResourceModule* resource;
    int task;
    Vec3f position;
    float lr = accesser->getPostureModule().getLr();
    Vec3f offset;
    fn_96_BC54(&offset, lbl_96_rodata_8, lbl_96_rodata_8, lbl_96_rodata_8);
    float scale = lbl_96_rodata_4;
    int value = 0;
    float size = accesser->getPostureModule().getScale();
    if (accesser->getWorkManageModule().getInt(0x1000004b) == 0) {
        offset.m_x = soValueAccesser::getConstantFloat(accesser, 0xfa5, 0);
        offset.m_y = soValueAccesser::getConstantFloat(accesser, 0xfa6, 0);
    } else if (accesser->getWorkManageModule().getInt(0x1000004b) == 1) {
        offset.m_x = soValueAccesser::getConstantFloat(accesser, 0xfa7, 0);
        offset.m_y = soValueAccesser::getConstantFloat(accesser, 0xfa8, 0);
    } else {
        offset.m_y = soValueAccesser::getConstantFloat(accesser, 0xfa9, 0);
    }
    Vec3f copy = accesser->getModelModule().getNodeGlobalPosition(0, false);
    position = copy;
    position.m_x += lr * (offset.m_x * size);
    position.m_y += offset.m_y * size;
    position.m_z = accesser->getGroundModule().getZ();
    if (accesser->getWorkManageModule().getInt(0x1000004b) != 2) {
        manager = g_ftManager;
        int entry = manager->getEntryIdFromTaskId(
            accesser->getLinkModule().getNodeTaskId(0), 0);
        Parameters params = *(Parameters*)g_ftCommonDataAccesser.getParam(
            manager->getFighter(entry, -1)->getFtKind());
        scale = *(float*)((char*)&params + 0x1a4);
        value = *(int*)((char*)&params + 0x1a8);
    }
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    posture = modules->m_postureModule;
    team = (TeamModule*)modules->m_teamModule;
    resource = modules->m_resourceModule;
    task = *(int*)((char*)accesser->m_stageObject + 0x28);
    fn_96_27E3C(object, task,
        resource->getResourceIdAccesser()->getEtcResId(),
        team->getValue()->getValue(),
        posture->getLr(), &position, scale, value,
        modules->m_workManageModule->getInt(0x1000004b));
    int id = object->getTaskId();
    accesser->getWorkManageModule().setInt(id, 0x1000004a);
    return 0;
}