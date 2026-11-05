#include <em/em_manager.h>
#include <so/stageobject.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct Event { int kind; char pad[8]; int a, b; };
class Catch {
public:
 virtual void f08(); virtual void f0c(); virtual void f10(); virtual void f14();
 virtual void f18(); virtual void f1c(); virtual void f20(); virtual void f24();
 virtual void f28(); virtual void f2c(); virtual void f30(bool, bool);
 virtual void f34(); virtual void f38(); virtual void f3c();
 virtual void f40(); virtual void f44(); virtual void f48();
 virtual void f4c(); virtual void f50(); virtual void f54(int);
};
struct CastBase { int a, b; };
struct CastObj : CastBase {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void v17(); virtual void v18();
 virtual void v19(int, int);
};
struct Self {
 char pad0[0x60]; soModuleAccesser* accesser; char pad64[0x4c];
 unsigned int id; char padb4[0x28]; char value[0x1b4-0xdc];
 soModuleEnumeration* modules;
};
extern "C" {
void fn_41_CBD4(emManager*, unsigned int);
void fn_27_6650(Self*, Event*, void*, StageObject*, int);
Vec3f* fn_41_5AC4(Vec3f*, float, float, float);
void fn_41_4C20(Self*, Vec3f*);
void fn_41_27A60(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_41_data_6F0[], lbl_41_data_14B8[], lbl_41_data_F54[], lbl_41_data_12A4[];
extern const float lbl_41_rodata_18;
}
extern "C" void fn_41_B8D4(Self* self, Event* event, void* arg, StageObject* object, int type) {
 switch (event->kind) {
 case 0:
  if (object->soGetKind() == 4 && type == 4 && self->modules->m_linkModule->isModelConstraint() == 1) {
   fn_41_CBD4(emManager::getInstance(), self->id); return;
  }
  break;
 case 61:
  if (object->soGetKind() == 4 && type == 4 && self->modules->m_linkModule->isModelConstraint() == 1) {
   fn_41_CBD4(emManager::getInstance(), self->id); return;
  }
  if (self->modules->m_linkModule->isModelConstraint() == 1) {
   Vec3f a, b;
   fn_41_5AC4(&a, lbl_41_rodata_18, lbl_41_rodata_18, lbl_41_rodata_18);
   fn_41_5AC4(&b, lbl_41_rodata_18, lbl_41_rodata_18, lbl_41_rodata_18);
   self->modules->m_linkModule->adjustModelConstraintPosture((Matrix*)&a, &b);
   ((StageObject*)self)->updateNodeSRT();
   self->accesser->m_enumerationStart->m_linkModule->removeModelConstraint(true);
  }
  break;
 case 10: {
  ((Catch*)self->accesser->m_enumerationStart->m_captureModule)->f54(0);
  self->modules->m_workManageModule->onFlag(0x12000010);
  soModelModule* model = self->modules->m_modelModule;
  Vec3f pos = model->getNodeGlobalPosition(soValueAccesser::getValueInt((soModuleAccesser*)self->value, 0x59e6, 0), false);
  ((Catch*)self->modules->m_captureModule)->f48();
  bool one = true;
  ((Catch*)self->modules->m_captureModule)->f30(one, one);
  fn_41_4C20(self, &pos);
  fn_41_27A60(__dynamic_cast(self->modules->m_linkModule, 0, lbl_41_data_6F0, lbl_41_data_14B8, one));
  CastObj* p = (CastObj*)__dynamic_cast(self->modules->m_groundModule, 8, lbl_41_data_F54, lbl_41_data_12A4, one);
  p->v19(5, 0);
  break;
 }
 case 11: {
  event->a = 0; event->b = 0;
  ((Catch*)self->modules->m_captureModule)->f3c();
  CastObj* p = (CastObj*)__dynamic_cast(self->modules->m_groundModule, 8, lbl_41_data_F54, lbl_41_data_12A4, 1);
  p->v19(0, 0);
  break;
 }
 }
 fn_27_6650(self, event, arg, object, type);
}
