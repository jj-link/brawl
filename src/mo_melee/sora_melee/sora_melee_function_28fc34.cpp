#include <so/so_external_value_accesser.h>
#include <gf/gf_task.h>
#pragma force_active on

class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(int, unsigned int); virtual void slot5(int, unsigned int);
 virtual void slot6(); virtual void slot7(); virtual void slot8(int); virtual int slot9(int);
 virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(float, unsigned int);
 virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17();
 virtual void slot18(unsigned int); virtual void slot19(unsigned int);
};
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char __RTTI__6gfTask[];
extern char lbl_27_data_248[];

inline StageObject* getObject(unsigned int id) {
 if (id == 0xffffffff) return 0;
 gfTask* task = gfTask::getTask(id);
 return task ? (StageObject*)__dynamic_cast(task, 0x3c, lbl_27_data_248, __RTTI__6gfTask, 0) : 0;
}

extern "C" void fn_27_28FC34(char* self, unsigned int id) {
 Object_vptr_0* work = (Object_vptr_0*)(self + 0x2aac);
 if (((Object_vptr_0*)(self + 0x27a8))->slot9(4)) ((Object_vptr_0*)(self + 0x27a8))->slot8(4);
 if (id == 0xffffffff) {
  work->slot19(0x12000007);
 } else {
  StageObject* obj = getObject(id);
  if (obj) {
   Vec3f pos = soExternalValueAccesser::getPos(obj);
   work->slot18(0x12000007);
   work->slot5(id, 0x10000013);
   work->slot13(pos.m_x, 0x11000007);
   work->slot13(pos.m_y, 0x11000008);
   if (id != 0xffffffff) ((Object_vptr_0*)(self + 0x27a8))->slot4(4, id);
  }
 }
}