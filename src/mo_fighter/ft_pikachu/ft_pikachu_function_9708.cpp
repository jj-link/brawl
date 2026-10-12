#include <ft/fighter.h>
#include <wn/weapon.h>
#include <so/so_module_accesser.h>

extern "C" {
extern const char lbl_98_data_26D4[], lbl_98_data_2F88[];
extern const char lbl_98_data_2E74[], lbl_98_data_2EA0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_14DB04(void*);
int fn_27_111364(ftOwner*);
void fn_98_1B334(Weapon*, unsigned int, int, int, Vec3f);
}

extern "C" bool fn_98_9708(Weapon* article, soModuleAccesser* accesser) {
    unsigned int taskId;
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_98_data_26D4, lbl_98_data_2F88, short(1)));
    accesser->getWorkManageModule().setInt(article->m_taskId, 0x20000003);
    taskId = fighter->m_taskId;
    int resource = fn_27_14DB04(__dynamic_cast(
        accesser->getResourceModule().getResourceIdAccesser(), 0,
        lbl_98_data_2E74, lbl_98_data_2EA0, short(1)));
    int ownerId = fn_27_111364(fighter->getOwner());
    Vec3f position;
    position = accesser->getPostureModule().getPos();
    fn_98_1B334(article, taskId, resource, ownerId, position);
    return true;
}
