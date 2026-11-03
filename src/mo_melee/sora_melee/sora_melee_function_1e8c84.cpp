#include <gf/gf_heap_manager.h>
#include <gf/gf_file_io_handle.h>
#include <so/event/so_event_system.h>
#pragma force_active on
extern "C" {
extern char lbl_27_data_47E98[];
extern char lbl_27_data_26D10[];
extern void* g_aiMgr;
void __dla__FPv(void*);
void __dl__FPv(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __dt__6gfTaskFv(void*, int);
void* fn_27_217684(void*, int);
void* fn_27_21C034(void*, int);
}
struct Obj {
 char pad0[0x3c]; char* vtable; char* observer;
 short manager; short event; short id;
 char pad4a[0xae];
 char* pF8; void* pFC; void* p100;
 char pad104[0x3c]; gfFileIOHandle handle; void* buffer; unsigned char owned;
 char pad149[0x1ff]; char* p348; char* p34c;
};
extern "C" Obj* fn_27_1E8C84(Obj* self, int flag) {
 if (self) {
  self->vtable = lbl_27_data_47E98;
  self->observer = lbl_27_data_47E98 + 0x64;
  if (self->pF8) { char* p=self->pF8; if(p) __dla__FPv(p-0x10); self->pF8=0; }
  if (self->pFC) { fn_27_217684(self->pFC,1); self->pFC=0; }
  if (self->p100) { fn_27_21C034(self->p100,1); self->p100=0; }
  if (self->p348) { char* p=self->p348; if(p) __dla__FPv(p-0x10); self->p348=0; }
  if (self->p34c) { char* p=self->p34c; if(p) __dla__FPv(p-0x10); self->p34c=0; }
  if (self->owned == 1 && self->buffer) { gfHeapManager::free(self->buffer); self->buffer=0; }
  g_aiMgr=0;
  __dt__14gfFileIOHandleFv(&self->handle,-1);
  char** obs=&self->observer;
  if (obs) { if (obs) {
   short id=self->manager;
   self->observer=lbl_27_data_26D10;
   if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == 1)
    soEventSystem::getInstance()->getManager(self->manager)->eraseObserver(self->event,self->id);
   self->id=-1; self->manager=-1;
  } }
  __dt__6gfTaskFv(self,0);
  if(flag>0) __dl__FPv(self);
 }
 return self;
}