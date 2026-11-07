#include <gf/gf_task_scheduler.h>
#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_96_data_6024[];
extern char lbl_96_data_69D8[];
}
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual int slot4(int);
};
#define V8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
#define V32(p) V8(p##a) V8(p##b) V8(p##c) V8(p##d)
struct Base { char pad[0x3c]; };
struct Target : Base {
 V32(a) V32(b) V32(c) V32(d) V32(e) V32(f) V32(g)
 virtual void extra();
 virtual void call();
};
struct Modules { char pad[0x64]; Object_vptr_0* work; };
struct Fighter { char pad[0xd8]; Modules* modules; };
extern "C" void fn_96_1BEC8(void*, Fighter* fighter) {
 int count = fighter->modules->work->slot4(0x20000006);
 for (int i = 0; i < count; i++) {
  unsigned int id = fighter->modules->work->slot4(0x20000000 + i);
  if (id != 0xffffffff) {
   gfTask* task = gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)10, id);
   if (task) {
    Target* obj = (Target*)__dynamic_cast(task, 0x3c, lbl_96_data_6024, lbl_96_data_69D8, 0);
    obj->call();
   }
  }
 }
}