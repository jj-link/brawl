#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on
extern "C" {
void* fn_27_1212A8(void*, int);
void fn_27_10E04C(void*, int);
void fn_27_50588(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__23soEventManageModuleImplFv(void*, short);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
extern char lbl_27_data_26230[], lbl_27_data_26CD0[], lbl_27_data_26CF8[], lbl_27_data_26D04[], lbl_27_data_26D10[];
}
class Object_vptr_0 {
public:
 virtual void slot0(int);
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
};
class Object_vptr_4c {
public:
 char pad[0x4c];
 virtual void slot0(int);
};
struct Obs { void* vtable; short manager, event, send; };
struct Entry { void* vtable; short manager, event; };
struct Obj {
 char pad0[0x3c];
 void* v3c;
 Obs a, b, c;
 void* v64;
 char pad68[0x60];
 Entry e;
 char padd0[0x84];
 void* p154;
 void* p158;
 Object_vptr_0* p15c;
};
extern "C" Obj* fn_27_108E0C(Obj* self, int flag) {
 if (self) {
  char* p=(char*)self;
  void* obj=self->p154;
  self->v64=lbl_27_data_26230;
  self->v3c=lbl_27_data_26230+8;
  self->a.vtable=lbl_27_data_26230+0x6c;
  self->b.vtable=lbl_27_data_26230+0x118;
  self->c.vtable=lbl_27_data_26230+0x130;
  if (obj) {
   ((Object_vptr_4c*)obj)->slot0(1);
  }
  self->p154=0;
  fn_27_1212A8(self->p158,1);
  Object_vptr_0* x=self->p15c;
  self->p158=0;
  if (x) x->slot0(1);
  self->p15c=0;
  if (p+0xc8) {
   if (p+0xd4 && p+0xe4) __destroy_arr(p+0xf0,fn_27_10E04C,12,8);
   if (p+0xc8 && p+0xc8) {
    short id=self->e.manager;
    self->e.vtable=lbl_27_data_26CD0;
    if (id != -1) soEventSystem::getInstance()->getManager(self->e.manager)->eraseUnit(self->e.event);
   }
  }
  __dt__23soEventManageModuleImplFv(p+0xb4,-1);
  if (p+0x8c && p+0xa0) __destroy_arr(p+0xac,fn_27_50588,8,1);
  if (p+0x58 && p+0x58) {
   short id=self->c.manager;
   self->c.vtable=lbl_27_data_26CF8;
   if (soEventSystem::getInstance()->getInstanceManager().isContain(id)==1)
    soEventSystem::getInstance()->getManager(self->c.manager)->eraseObserver(self->c.event,self->c.send);
   self->c.send=-1;
   self->c.manager=-1;
  }
  if (p+0x4c && p+0x4c) {
   short id=self->b.manager;
   self->b.vtable=lbl_27_data_26D04;
   if (soEventSystem::getInstance()->getInstanceManager().isContain(id)==1)
    soEventSystem::getInstance()->getManager(self->b.manager)->eraseObserver(self->b.event,self->b.send);
   self->b.send=-1;
   self->b.manager=-1;
  }
  if (p+0x40 && p+0x40) {
   short id=self->a.manager;
   self->a.vtable=lbl_27_data_26D10;
   if (soEventSystem::getInstance()->getInstanceManager().isContain(id)==1)
    soEventSystem::getInstance()->getManager(self->a.manager)->eraseObserver(self->a.event,self->a.send);
   self->a.send=-1;
   self->a.manager=-1;
  }
  __dt__6gfTaskFv(self,0);
  if (flag>0) __dl__FPv(self);
 }
 return self;
}