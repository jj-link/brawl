#include <types.h>
#include <so/event/so_event_system.h>
#include <so/model/so_model_module_simple.h>
#pragma force_active on
extern "C" {
void* fn_27_C31CC(void*, short);
void* fn_27_26F2F0(void*, int);
void* fn_27_3544C(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_252D0(void*, short);
void* __dt__19soModelModuleSimpleFv(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void fn_27_845D8(void*, int);
void fn_27_84598(void*, int);
void fn_27_50588(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_3994(void*, int);
extern char lbl_27_data_25F88[], lbl_27_data_25FB0[], lbl_27_data_731C[];
}
struct Entry { void* vtable; short manager; short event; };
struct Obs { void* vtable; short manager; short event; short send; };
struct Object {
 char p0[0x64]; Obs obs; char p70[0x1e0-0x70];
 Entry e1; char p1e8[0x218-0x1e8]; Entry e2;
};
extern "C" Object* fn_27_262FCC(Object* self, int flag) {
 if (self) {
  char* p = (char*)self;
  fn_27_C31CC(p+0x340,-1);
  fn_27_26F2F0(p+0x338,-1);
  fn_27_3544C(p+0x2fc,-1);
  fn_27_B5324(p+0x2b8,-1);
  fn_27_252D0(p+0x264,-1);
  __dt__19soModelModuleSimpleFv(p+0x250,-1);
  if (p+0x218) {
   if (p+0x224) { if (p+0x234) __destroy_arr(p+0x240,fn_27_845D8,12,1); }
   if (p+0x218) { if (p+0x218) {
    short id=self->e2.manager;
    self->e2.vtable=lbl_27_data_25F88;
    if (id != -1) soEventSystem::getInstance()->getManager(self->e2.manager)->eraseUnit(self->e2.event);
   } }
  }
  if (p+0x1e0) {
   if (p+0x1ec) { if (p+0x1fc) __destroy_arr(p+0x208,fn_27_84598,12,1); }
   if (p+0x1e0) { if (p+0x1e0) {
    short id=self->e1.manager;
    self->e1.vtable=lbl_27_data_25FB0;
    if (id != -1) soEventSystem::getInstance()->getManager(self->e1.manager)->eraseUnit(self->e1.event);
   } }
  }
  __dt__23soEventManageModuleImplFv(p+0x1cc,-1);
  if (p+0x18c) { if (p+0x1a0) __destroy_arr(p+0x1ac,fn_27_50588,8,4); }
  __dt__16soModuleAccesserFv(p+0xa8,-1);
  if (p+0x64) { if (p+0x64) {
   short id=self->obs.manager;
   self->obs.vtable=lbl_27_data_731C;
   if (soEventSystem::getInstance()->getInstanceManager().isContain(id)==1)
    soEventSystem::getInstance()->getManager(self->obs.manager)->eraseObserver(self->obs.event,self->obs.send);
   self->obs.send=-1;
   self->obs.manager=-1;
  } }
  fn_27_3994(self,0);
  if (flag>0) __dl__FPv(self);
 }
 return self;
}