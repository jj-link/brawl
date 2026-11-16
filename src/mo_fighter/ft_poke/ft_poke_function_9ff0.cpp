#include <wn/weapon.h>
#include <ft/fighter.h>
#include <so/so_value_accesser.h>
#include <so/resource/so_resource_module_impl.h>
#include <so/resource/so_resource_id_accesser.h>
#include <so/work/so_work_manage_module_impl.h>

#pragma force_active on

struct Local {
    float x, y, z;
    Local(const Local&);
};

class Object_vptr_0 {
public:
    virtual void fn_116_7384();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Local slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
};

extern "C" {
extern const char lbl_116_data_2484[], lbl_116_data_2D00[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
void fn_116_105AC(Weapon*, unsigned, unsigned, int, const Local*, float, float);
}

extern "C" int fn_116_9FF0(Weapon* self, soModuleAccesser* accesser) {
    Object_vptr_0* node;
    soResourceModule* resource;
    int taskId;
    StageObject* obj;
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    node = reinterpret_cast<Object_vptr_0*>(modules->m_postureModule);
    obj = accesser->m_stageObject;
    resource = modules->m_resourceModule;
    taskId = obj->m_taskId;
    float vf;
    float cf;
    cf = soValueAccesser::getConstantFloat(accesser, 0xFB1, 0);
    vf = node->slot9();
    Local local = node->slot4();
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(obj, 0x3C, lbl_116_data_2484, lbl_116_data_2D00, 1));
    node = reinterpret_cast<Object_vptr_0*>(fn_27_111364(fighter->getOwner()));
    int iv = resource->getResourceIdAccesser()->getEtcResId();
    fn_116_105AC(self, taskId, iv, reinterpret_cast<int>(node), &local, vf, cf);
    int value = self->getTaskId();
    accesser->m_enumerationStart->m_workManageModule->setInt(value, 0x10000041);
    return 1;
}
