#include <so/event/so_event_system.h>
#pragma force_active on
extern "C" char lbl_27_data_1180[];
extern "C" void __dl__FPv(void*);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_27_C940C(void*, int);
class soAnimCmdEventObserver;
template <class T> struct soEventObserver { static void __vt(int, int); };
struct EvSys {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual u32 v6(s16);
};
struct Obj {
 u32 m0; u32 m4; void* v8; s16 mC; s16 mE; s16 m10; s16 m12;
 void* v14; s16 m18; s16 m1A; s16 m1C;
};
extern "C" void* fn_27_313D94(void* arg, s32 flag) {
 if (arg) {
  Obj* p = (Obj*)arg;
  if ((char*)p + 0x24 && (char*)p + 0x34)
   __destroy_arr((char*)p + 0x40, fn_27_C940C, 0x10, 7);
  if (p) {
   if ((char*)p + 0x14 && (char*)p + 0x14) {
    s16 id = p->m18;
    p->v14 = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
    if (((EvSys*)soEventSystem::getInstance())->v6(id) == 1) {
     soEventManager* mgr = soEventSystem::getInstance()->getManager(p->m18);
     mgr->eraseObserver(p->m1A, p->m1C);
    }
    p->m1C = -1; p->m18 = -1;
   }
   if ((char*)p + 0x8 && (char*)p + 0x8) {
    s16 id = p->mC;
    p->v8 = (void*)lbl_27_data_1180;
    if (((EvSys*)soEventSystem::getInstance())->v6(id) == 1) {
     soEventManager* mgr = soEventSystem::getInstance()->getManager(p->mC);
     mgr->eraseObserver(p->mE, p->m10);
    }
    p->m10 = -1; p->mC = -1;
   }
  }
  if (flag > 0) __dl__FPv(arg);
 }
 return arg;
}