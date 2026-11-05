#include <ft/fighter.h>
#include <wn/weapon.h>
#include <so/so_module_accesser.h>
#pragma force_active on

class Class_824C {
public:
    virtual void fn_98_744C();
    virtual void fn_98_13A4C();
    virtual void fn_98_14CF8();
    virtual void fn_98_14CF4();
    virtual void fn_98_14CF0();
    virtual void fn_98_14CEC();
    virtual void fn_98_14CE4();
    virtual void fn_98_14D2C();
    virtual void fn_98_14D24();
    virtual void fn_98_14D1C();
    virtual void fn_98_14D14();
    virtual void fn_98_14D0C();
    virtual void fn_98_14CA4();
    virtual void fn_98_14CD8();
    virtual void fn_98_14CCC();
    virtual void fn_98_14CC4();
};
class Class_8424 {
public:
    virtual void fn_98_744C();
    virtual void fn_98_139F0();
    virtual void fn_98_14EE4();
    virtual void fn_98_14EDC();
    virtual void fn_98_14ED4();
    virtual void fn_98_14ECC();
    virtual void fn_98_14EC4();
    virtual void fn_98_14EBC();
    virtual void fn_98_14EB4();
    virtual void fn_98_14EAC();
    virtual void fn_98_14EA4();
    virtual void fn_98_14E9C();
    virtual void fn_98_14E94();
    virtual void fn_98_14E8C();
    virtual void fn_98_14E3C();
    virtual void fn_98_14E84();
};

extern "C" {
extern const char lbl_98_data_600[], lbl_98_data_2F88[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
void fn_98_17838(Weapon*, unsigned int, int, const Vec3f*, int, Fighter*);
int fn_98_984C(Fighter*, Weapon*);
}

extern "C" int fn_98_9620(Weapon* article, soModuleAccesser* accesser) {
    unsigned int taskId;
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_98_data_600, lbl_98_data_2F88, short(1)));
    taskId = fighter->m_taskId;
    int owner = fn_27_111364(fighter->getOwner());
    Vec3f position = accesser->getPostureModule().getPos();
    int resource = accesser->getResourceModule().getResourceIdAccesser()->getEtcResId();
    fn_98_17838(article, taskId, owner, &position, resource, fighter);
    fn_98_984C(fighter, article);
    return 0;
}