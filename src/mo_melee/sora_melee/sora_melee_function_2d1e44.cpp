#include <ec/ec_mgr.h>
#include <string.h>
#pragma force_active on

class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6(int, bool);
};
struct Entry { char pad[16]; void* resource; };
struct Pool { Entry entries[1]; };
struct Task { char pad[0x144]; Pool pool; };
struct Item { char pad[8]; char* name; char pad2[0x48]; short x; short y; };
struct Self { char pad[0x168ac]; int index; char pad2[0x40]; unsigned char state; char pad3[3]; Item* item; char pad4[0x154]; unsigned long id; };
extern Task* lbl_27_bss_7328;
extern char lbl_27_data_7B470[];
extern char lbl_27_data_7B480[];
extern const float lbl_27_rodata_61C8;
extern const float lbl_27_rodata_626C;
extern "C" void fn_27_2D68C4(Pool*, int*);
extern "C" int fn_27_2D66E0(Pool*, Item*);
extern "C" Object_vptr_0* fn_800607C8(ecMgr*, unsigned long);
extern "C" void fn_80060A18(ecMgr*, unsigned long, const char*, int, void*, int);
extern "C" void fn_8006097C(ecMgr*, unsigned long, const char*, const char*, void*, int);

inline bool valid(Task* t, int i) { if (i < 0 || t->pool.entries[i].resource == 0) return false; else return true; }
inline void* resource(Task* t, int i) {
 Entry* e;
 if (i < 0 || !valid(t, i) || (e = &t->pool.entries[i], e->resource == 0))
  return 0;
 else
  return &e->resource;
}
inline void loadFallback(Task* task, unsigned long id, Item* item) {
 char name[128];
 strcpy(name, item->name);
 name[strlen(name)-6] = 0;
 fn_8006097C(g_ecMgr, id, lbl_27_data_7B470, name, (char*)task + 0x678, 1);
 fn_8006097C(g_ecMgr, id, lbl_27_data_7B480, name, &task->pool.entries[66].pad[12], 1);
}
extern "C" void fn_27_2D1E44(Self* self, Item* item) {
 Task* task;
 ecMgr* mgr;
 mgr = g_ecMgr;
 task = lbl_27_bss_7328;
 if (item) {
  if (self->item != item) {
   self->item = item;
   fn_27_2D68C4(&task->pool, &self->index);
   self->index = fn_27_2D66E0(&task->pool, item);
   self->state = 1;
   ecMgr* mgr2 = g_ecMgr;
   Task* task2 = lbl_27_bss_7328;
   if (valid(task2, self->index)) {
    fn_80060A18(mgr2, self->id, lbl_27_data_7B470, 0, resource(task2, self->index), 0);
    fn_80060A18(mgr2, self->id, lbl_27_data_7B480, 0, resource(task2, self->index), 0);
    self->state = 0;
   } else if (item) {
    loadFallback(task2, self->id, item);
    self->state = 2;
   }
   Vec3f scale((float)item->x / lbl_27_rodata_626C,
               (float)item->y / lbl_27_rodata_626C, lbl_27_rodata_61C8);
   mgr->setScl(self->id, &scale);
   Object_vptr_0* obj = fn_800607C8(mgr, self->id);
   if (obj) {
    obj->slot6(1, false);
    obj->slot6(6, false);
    obj->slot6(7, false);
   }
   mgr->setMdlAnmIdx(self->id, 0, 1);
  }
 } else {
  fn_27_2D68C4(&task->pool, &self->index);
  self->state = 0;
  Object_vptr_0* obj = fn_800607C8(mgr, self->id);
  if (obj) {
   obj->slot6(1, true);
   obj->slot6(6, true);
   obj->slot6(7, true);
  }
  self->item = 0;
 }
}
