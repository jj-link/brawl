#include <ft/fighter.h>
#include <so/so_module_accesser.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void fn_123_6E08(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual int slot15();
 virtual void slot16(); virtual void slot17();
};
struct Class_6558_base { char pad[8]; };
class Class_6558 : public Class_6558_base {
public:
 virtual void fn_123_FF80(); virtual void fn_123_FDA8(); virtual void fn_123_FDB8();
 virtual void fn_123_FF20(); virtual Object_vptr_0* fn_123_FD74();
};
extern "C" {
extern const char lbl_123_data_1984[], lbl_123_data_2238[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_123_90FC(Vec2f*, const Vec2f*);
int fn_27_111364(ftOwner*);
void fn_123_13098(void*, int, int, int, Vec2f*, float, bool);
}
extern "C" int fn_123_95DC(void* self, soModuleAccesser* accesser) {
 Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(accesser->m_stageObject, 0x3c, lbl_123_data_1984, lbl_123_data_2238, short(1)));
 Class_6558* resource;
 int task;
 Vec3f position = accesser->getPostureModule().getPos();
 Vec2f pos;
 fn_123_90FC(&pos, (Vec2f*)&position);
 bool flag = true;
 if (!accesser->getWorkManageModule().isFlag(0x22000010)) flag = false;
 const soModuleEnumeration* modules = accesser->m_enumerationStart;
 resource = (Class_6558*)modules->m_resourceModule;
 task = accesser->m_stageObject->m_taskId;
 float lr = modules->m_postureModule->getLr();
 int owner = fn_27_111364(fighter->getOwner());
 int id = resource->fn_123_FD74()->slot15();
 fn_123_13098(self, task, id, owner, &pos, lr, flag);
 return 1;
}