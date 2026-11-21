#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on
class soGimmickEventObserver;
template <> class soEventUnitWrapper<soGimmickEventObserver> { public: static unsigned char __RTTI[]; };
struct Pack { void* vt; s16 manager; s16 event; void* list; s32 other; };
struct Event { s32 kind; s32 send; u8 up; u8 down; };
class CheckModule { public: virtual void a(); virtual void b(); virtual void c(); virtual int d(); };
class ControlModule {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
 virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
 virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
 virtual void f16(); virtual void f17(); virtual float f18();
};
struct Modules { char pad0[0x14]; CheckModule* check; char pad18[0x44]; ControlModule* control; };
struct Object { char pad0[0xD8]; Modules* modules; };
struct Self { char pad0[5]; s8 direction; };
struct Arg { char pad0[8]; s32 id; };
extern "C" {
extern unsigned char lbl_27_data_2DC60[0xC];
extern unsigned char lbl_27_data_2DC20[0x10];
extern unsigned char __RTTI__11soEventUnit[8];
extern f32 lbl_27_rodata_1F28;
extern f32 lbl_27_rodata_1F2C;
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_27_AA42C(void*, void*, void*, s32);
}
inline void resolve(Pack& pk, void* result) {
 s16 id = pk.manager;
 if (id > 0 && id > -1) {
  if (soEventSystem::getInstance()->getInstanceManager().isContain(id)) {
   soEventManager* mgr = soEventSystem::getInstance()->getManager(pk.manager);
   if (mgr->getObserverCapacity(pk.event) == 0) pk.list = 0;
   else {
    s16 event = pk.event;
    soEventManager* mgr2 = soEventSystem::getInstance()->getManager(pk.manager);
    if (mgr2->getObserverCapacity(event) == 0) result = 0;
    else {
     soEventUnit* unit = mgr2->getEventUnit(event);
     void* w = __dynamic_cast(unit, 0, soEventUnitWrapper<soGimmickEventObserver>::__RTTI, __RTTI__11soEventUnit, 0);
     if (w == 0) result = 0;
     else {
      class UnitView {
      public:
       virtual void a(); virtual void b(); virtual void c(); virtual void d();
       virtual void e(); virtual void f(); virtual void g(); virtual void* get();
      };
      result = ((UnitView*)w)->get();
     }
    }
    pk.list = result;
   }
  }
 }
}
extern "C" int fn_27_1556D4(Self* self, Object* object, Arg* arg) {
 s16 id;
 soEventManager* mgr2;
 Pack pk1; Event ev1; Pack pk2; Event ev2;
 if (object->modules->check->d() == 0) {
  void* result = 0;
  self->direction = 0;
  if (object->modules->control->f18() < lbl_27_rodata_1F28) {
   id = (s16)arg->id;
   pk1.vt = lbl_27_data_2DC60; pk1.manager = id; pk1.event = 3; pk1.list = result;
   {
   if (id > 0 && id > -1) {
    if (soEventSystem::getInstance()->getInstanceManager().isContain(id)) {
     soEventManager* mgr = soEventSystem::getInstance()->getManager(pk1.manager);
     if (mgr->getObserverCapacity(pk1.event) == 0) pk1.list = 0;
     else {
      s16 event = pk1.event;
      mgr2 = soEventSystem::getInstance()->getManager(pk1.manager);
      if (mgr2->getObserverCapacity(event) == 0) result = 0;
      else {
       soEventUnit* unit = mgr2->getEventUnit(event);
       void* w = __dynamic_cast(unit, 0, soEventUnitWrapper<soGimmickEventObserver>::__RTTI, __RTTI__11soEventUnit, 0);
       if (w == 0) result = 0;
       else {
        class UnitView {
        public:
         virtual void a(); virtual void b(); virtual void c(); virtual void d();
         virtual void e(); virtual void f(); virtual void g(); virtual void* get();
        };
        result = ((UnitView*)w)->get();
       }
      }
      pk1.list = result;
     }
    }
   }
  }
   pk1.vt = lbl_27_data_2DC20; pk1.other = -1;
   ev1.kind = 0x2B; ev1.send = 0; ev1.up = 0; ev1.down = 0;
   fn_27_AA42C(&pk1, &ev1, object, -1);
   if (ev1.down == 1) self->direction = -1;
  } else if (object->modules->control->f18() > lbl_27_rodata_1F2C) {
   id = (s16)arg->id;
   pk2.vt = lbl_27_data_2DC60; pk2.manager = id; pk2.event = 3; pk2.list = result;
   {
   if (id > 0 && id > -1) {
    if (soEventSystem::getInstance()->getInstanceManager().isContain(id)) {
     soEventManager* mgr = soEventSystem::getInstance()->getManager(pk2.manager);
     if (mgr->getObserverCapacity(pk2.event) == 0) pk2.list = 0;
     else {
      s16 event = pk2.event;
      soEventManager* mgr2 = soEventSystem::getInstance()->getManager(pk2.manager);
      if (mgr2->getObserverCapacity(event) == 0) result = 0;
      else {
       soEventUnit* unit = mgr2->getEventUnit(event);
       void* w = __dynamic_cast(unit, 0, soEventUnitWrapper<soGimmickEventObserver>::__RTTI, __RTTI__11soEventUnit, 0);
       if (w == 0) result = 0;
       else {
        class UnitView {
        public:
         virtual void a(); virtual void b(); virtual void c(); virtual void d();
         virtual void e(); virtual void f(); virtual void g(); virtual void* get();
        };
        result = ((UnitView*)w)->get();
       }
      }
      pk2.list = result;
     }
    }
   }
  }
   pk2.vt = lbl_27_data_2DC20; pk2.other = -1;
   ev2.kind = 0x2B; ev2.send = 0; ev2.up = 0; ev2.down = 0;
   fn_27_AA42C(&pk2, &ev2, object, -1);
   if (ev2.up == 1) self->direction = 1;
  }
  if (self->direction != 0) {
   object->modules->control->f15();
   return 1;
  }
 }
 return 0;
}