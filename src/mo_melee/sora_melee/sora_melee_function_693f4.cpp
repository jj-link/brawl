#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on
extern "C" {
extern char lbl_27_data_7AF0[], lbl_27_data_7AB0[], lbl_27_data_7A08[], lbl_27_data_7A10[];
extern const float lbl_27_rodata_930;
extern char __vt__22soAnimCmdEventObserver[], __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
}
class Q {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6(); virtual s16 get();
};
class Obs { public: virtual void attach(s32, s32); };
class Unit {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual s32 get();
};
struct Self {
 void* vt; Obs obs; s16 a,b,c; char pad[2]; void* vt2; s16 id, unit; s32 value;
 void* arg; s32 x,y; float f,g,h; u8 flags : 7; u8 other : 1;
};
inline s32 getResult(Self* self) {
 s16 id = self->unit;
 soEventManager* mgr = soEventSystem::getInstance()->getManager(self->id);
 if (mgr->getObserverCapacity(id) == 0) return 0;
 Unit* unit = (Unit*)__dynamic_cast(mgr->getEventUnit(id), 0, lbl_27_data_7A08, __RTTI__11soEventUnit, 0);
 if (unit == 0) return 0;
 return unit->get();
}
extern "C" void* fn_27_693F4(Self* self, u8* arg) {
 s32 result = 0;
 s32 eid;
 self->vt = lbl_27_data_7AF0;
 u8* obj = *(u8**)(*(u8**)(arg + 0xD8) + 0x80);
 s16 r = ((Q*)(obj + 8))->get();
 self->a = -1; self->b = 5; self->c = -1;
 *(void**)&self->obs = __vt__22soAnimCmdEventObserver;
 self->obs.attach((s32)r, -1);
 obj = *(u8**)(*(u8**)(arg + 0xD8) + 0x80);
 eid = (s16)((Q*)(obj + 8))->get();
 self->vt2 = lbl_27_data_7AB0;
 self->id = eid; self->unit = 18; self->value = result;
 if (eid > 0 && eid > -1) {
  if (soEventSystem::getInstance()->getInstanceManager().isContain(eid)) {
   if (soEventSystem::getInstance()->getManager(self->id)->getObserverCapacity(self->unit) == 0)
    self->value = 0;
   else {
    result = getResult(self);
    self->value = result;
   }
  }
 }
 self->vt = lbl_27_data_7A10;
 *(void**)&self->obs = lbl_27_data_7A10 + 0x34;
 self->vt2 = lbl_27_data_7A10 + 0x48;
 self->arg = arg; self->x = 0; self->y = 0;
 self->f = lbl_27_rodata_930; self->g = lbl_27_rodata_930; self->h = lbl_27_rodata_930;
 self->flags = 0;
 return self;
}