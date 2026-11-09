#include <gf/gf_task_scheduler.h>
#include <mt/mt_vector.h>
#pragma force_active on
extern const float lbl_27_rodata_7D70;
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual unsigned int slot4(unsigned int);
 virtual void slot5(int,unsigned int,void*);
 virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13();
 virtual void slot14(); virtual void slot15(int,void*); virtual void slot16();
 virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(int);
};
class Posture {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual Vec3f slot4();
 virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16();
 virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20();
};
struct Modules {
 char pad0[0xc]; Posture* m0c; char pad10[0x44]; Object_vptr_0* m54;
 char pad58[0xc]; Object_vptr_0* m64; char pad68[0x20]; Object_vptr_0* m88;
};
struct Module { char pad[0xd8]; Modules* modules; };
struct ArrElem { int value; char pad[0x18]; };
struct Self { char pad[0x60]; Module* m60; char pad64[0x201c-0x64]; ArrElem arr[3]; };
struct Param {
 unsigned int id; unsigned char flag; char pad[3]; Vec3f pos;
 Param(const Vec3f& p) : id(0x458), flag(0), pos(p) {}
};
extern "C" void fn_27_3949CC(Self* self) {
 Module* mod = self->m60;
 unsigned int taskId = mod->modules->m64->slot4(0x1000000b);
 if (taskId != 0) {
  gfTask* task = gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)0x12, taskId);
  if (task != 0) task->exit();
  self->m60->modules->m64->slot5(0,0x1000000b,self->m60);
 }
 for (unsigned int i=0; i<3; ++i) {
  if (self->arr[i].value) {
   mod->modules->m88->slot20(self->arr[i].value);
   self->arr[i].value=0;
  }
 }
 Param param(Vec3f(lbl_27_rodata_7D70,lbl_27_rodata_7D70,lbl_27_rodata_7D70));
 param.pos = mod->modules->m0c->slot4();
 mod->modules->m54->slot15(3,&param);
}