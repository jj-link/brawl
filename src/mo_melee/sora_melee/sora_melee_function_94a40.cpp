#include <so/event/so_event_system.h>
#include <types.h>
#pragma force_active on
class Container {
public:
 virtual void fn08(); virtual void* fn0c(s32); virtual void fn10(); virtual u32 fn14();
 virtual void fn18(); virtual void fn1c(); virtual void fn20(); virtual void fn24();
 virtual void fn28(); virtual void fn2c(); virtual void fn30(); virtual void fn34(); virtual void fn38(s32);
};
class Event {
public:
 virtual void fn08(); virtual void fn0c(); virtual void fn10(); virtual void fn14();
 virtual void fn18(); virtual void fn1c(); virtual void fn20(); virtual s32 fn24(); virtual void* fn28();
 virtual void fn2c(); virtual void fn30(); virtual void fn34(); virtual void fn38(); virtual void fn3c();
 virtual void fn40(); virtual void fn44(); virtual void fn48(); virtual void fn4c(); virtual void fn50();
 virtual void fn54(); virtual void fn58(); virtual void fn5c(); virtual void fn60(); virtual void fn64();
 virtual void fn68(); virtual void fn6c(); virtual void fn70(s32);
};
extern "C" soEventSystem* getInstance__13soEventSystemFv();
extern "C" soEventManager* getManager__13soEventSystemFl(soEventSystem*, s32);
struct Self { char pad[0x2C]; Container* m_2c; char pad30[4]; Container* m_34; };
extern "C" void fn_27_94A40(Self* self, void* arg1) {
 s16 neg = -1;
 s32 j = 0;
 s32 n;
 Event* ev2;
 s32 t;
 s32 i = self->m_2c->fn14() - 1;
 Event* ev1;
 while (i >= 0) {
  if (*(Event**)self->m_2c->fn0c(i) != 0 &&
      arg1 == (*(Event**)self->m_2c->fn0c(i))->fn28()) {
   ev1 = *(Event**)self->m_2c->fn0c(i);
   ev2 = *(Event**)self->m_2c->fn0c(i);
   n = self->m_34->fn14();
   for (j = 0; j < n; j++) {
    s32 id = ev2->fn24();
    void* entry = self->m_34->fn0c(j);
    if ((s16)id != neg) {
     t = *(s16*)((char*)entry + 4);
     if ((s16)id == t) {
      if (getInstance__13soEventSystemFv()->m_instanceManager.isContain(t) == 1) {
       getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)((char*)entry + 4))
        ->eraseObserver(*(s16*)((char*)entry + 6), *(s16*)((char*)entry + 8));
      }
      *(s16*)((char*)entry + 8) = neg;
      *(s16*)((char*)entry + 4) = neg;
     }
    }
   }
   self->m_2c->fn38(i);
   ev2->fn70(1);
   ev1->fn1c();
  }
  i--;
 }
}