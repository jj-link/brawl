#include <gf/gf_task_scheduler.h>
#pragma force_active on
struct Entry {
 char pad[12]; unsigned long id; char pad10[17];
 unsigned char active, category, pad23, arg24, pad25[2], arg27;
};
class soNullable {
public:
 virtual void isNull();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual unsigned int slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void slot24();
 virtual void slot25();
 virtual float slot26(unsigned char, unsigned char);
 virtual void slot27();
 virtual void slot28();
 virtual void slot29();
 virtual void slot30();
 virtual void slot31();
 virtual void slot32();
 virtual void slot33();
 virtual void slot34();
 virtual void slot35();
 virtual void slot36();
 virtual void slot37();
 virtual void slot38();
 virtual void slot39();
 virtual void slot40();
 virtual void slot41();
 virtual int slot42(unsigned char, unsigned char);
};
class Mode {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual unsigned int slot6();
 virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25();
 virtual float slot26(int, Mode*, float);
};
struct Modules { char pad[0xc8]; Mode* mode; };
struct Access { char pad[0xd8]; Modules* modules; };
struct Data { char pad[0x98]; float value; };
class Array {
public:
 virtual void slot0(); virtual Data* slot1(int); virtual void slot2(); virtual int slot3();
};
class Handler {
public:
 virtual void slot0();
 virtual void slot1(soNullable*, Entry*, int, Access*, float, float, float);
 virtual void slot2(void*, Entry*, int, Access*);
};
struct Self {
 char pad[0x1c]; Access* access; char pad20[8]; char collection[0x20];
 Array* array; Handler* handler; char pad50; unsigned char flag;
};
extern "C" {
 extern const char lbl_27_data_248[];
 extern const char __RTTI__6gfTask[];
 void* __dynamic_cast(void*, long, const void*, const void*, long);
 void* fn_27_36A58(void*, int);
 float fn_27_379A0(void*, int);
 soNullable* fn_27_8CD44(void*);
 void* fn_27_8CD84(void*);
 Mode* fn_27_8CDD4(void*);
 Entry* fn_8015C1B0(void*, Entry*);
}
extern "C" void fn_27_496EC(Self* self) {
 self->flag = 0;
 int count = self->array->slot3();
 for (int i = 0; i < count; ++i) {
  void* collection = fn_27_36A58(self->collection, i);
  Entry* entry = 0;
  while ((entry = fn_8015C1B0(collection, entry)) != 0) {
   gfTask* found = gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)entry->category, entry->id);
   if (found != 0) {
    void* task = __dynamic_cast(found, 0x3c, lbl_27_data_248, __RTTI__6gfTask, 0);
    if (entry->active == 0) {
     soNullable* posture = fn_27_8CD44(task);
     Mode* mode = fn_27_8CDD4(task);
     float v;
     float value = posture->slot26(entry->arg24, entry->arg27);
     if (self->access->modules->mode->slot6() == 1 && mode->slot6() == 1) {
      task = self->access->modules->mode;
      value = ((Mode*)task)->slot26(posture->slot42(entry->arg24, entry->arg27), mode, value);
     }
     v = self->array->slot1(i)->value;
     float other = fn_27_379A0(self->collection, i);
     self->handler->slot1(posture, entry, i, self->access, value, other, v);
    } else {
     self->handler->slot2(fn_27_8CD84(task), entry, i, self->access);
    }
    self->flag = 1;
   }
  }
 }
}
