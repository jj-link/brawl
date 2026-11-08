#include <types.h>
#include <gf/gf_task.h>
#pragma force_active on
extern unsigned char lbl_27_bss_7B0C[];
extern char lbl_27_data_2D0F0[];
extern "C" char __RTTI__6gfTask[];
extern "C" s32 fn_27_30FACC(void*, u32, s32, void*, u32);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual int slot4(u32); virtual void slot5(int,u32); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual int slot16();
};
class Class_8F268 {
public:
 virtual void fn_27_356830(); virtual void fn_27_2D9350(); virtual void fn_27_2D934C(); virtual void fn_27_2D9348();
 virtual void fn_27_2D9344(); virtual void fn_27_2D9340(); virtual void fn_27_2D933C(); virtual void fn_27_2D9338();
 virtual void fn_27_2D9334(); virtual void fn_27_2D932C(); virtual void fn_27_356870(); virtual void fn_27_2D9320();
 virtual void fn_27_2D9354(); virtual void fn_27_2D9318(); virtual void fn_27_2D9314(); virtual void fn_27_2D9310(); virtual void fn_27_2D9308();
};
struct Modules { char pad[0x64]; Object_vptr_0* work; char pad68[8]; Object_vptr_0* status; };
struct Object { char pad[0xd8]; Modules* modules; };
struct Event { char pad[0xc]; int id; };
struct TargetBase { char pad[0x3c]; };
class Target : public TargetBase { public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
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
 virtual void slot26();
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
 virtual void slot42();
 virtual void slot43();
 virtual void slot44();
 virtual void slot45();
 virtual void slot46();
 virtual void slot47();
 virtual void slot48();
 virtual void slot49();
 virtual void slot50();
 virtual void slot51();
 virtual void slot52();
 virtual void slot53();
 virtual void slot54();
 virtual void slot55();
 virtual void slot56();
 virtual void slot57();
 virtual void slot58();
 virtual void slot59();
 virtual void slot60();
 virtual void slot61();
 virtual void slot62();
 virtual void slot63();
 virtual void slot64();
 virtual void slot65();
 virtual void slot66();
 virtual void slot67();
 virtual void slot68();
 virtual void slot69();
 virtual void slot70();
 virtual void slot71();
 virtual void slot72();
 virtual void slot73();
 virtual void slot74();
 virtual void slot75();
 virtual void slot76();
 virtual void slot77();
 virtual void slot78();
 virtual void slot79();
 virtual void slot80();
 virtual void slot81();
 virtual void slot82();
 virtual void slot83();
 virtual void slot84();
 virtual void slot85();
 virtual void slot86();
 virtual void slot87();
 virtual void slot88();
 virtual void slot89();
 virtual void slot90();
 virtual void slot91();
 virtual void slot92();
 virtual void slot93();
 virtual void slot94();
 virtual void slot95();
 virtual void slot96();
 virtual void slot97();
 virtual void slot98();
 virtual void slot99();
 virtual void slot100();
 virtual void slot101();
 virtual void slot102();
 virtual void slot103();
 virtual void slot104();
 virtual void slot105();
 virtual void slot106();
 virtual void slot107();
 virtual void slot108();
 virtual void slot109();
 virtual void slot110();
 virtual void slot111();
 virtual void slot112();
 virtual void slot113();
 virtual void slot114();
 virtual void slot115();
 virtual void slot116();
 virtual void slot117();
 virtual void slot118();
 virtual void slot119();
 virtual void slot120();
 virtual void slot121();
 virtual void slot122();
 virtual void slot123();
 virtual void slot124();
 virtual void slot125();
 virtual void slot126();
 virtual void slot127();
 virtual void slot128();
 virtual void slot129();
 virtual void slot130();
 virtual void slot131();
 virtual void slot132();
 virtual void slot133();
 virtual void slot134();
 virtual void slot135();
 virtual void slot136();
 virtual void slot137();
 virtual void slot138();
 virtual void slot139();
 virtual void slot140();
 virtual void slot141();
 virtual void slot142();
 virtual void slot143();
 virtual void slot144();
 virtual void slot145();
 virtual void slot146();
 virtual void slot147();
 virtual void slot148();
 virtual void slot149();
 virtual void slot150();
 virtual int check();
};
inline gfTask* findTask(int id) { gfTask* task = 0; if ((u32)(id + 0x10000) != 0xffff) task = gfTask::getTask(id); return task; }
extern "C" void fn_27_356870(void*, Event* event, Object* obj) {
 int result = fn_27_30FACC(lbl_27_bss_7B0C, 0, obj->modules->status->slot16(), obj, 1);
 if (result == 0x112 || result == 0x117) {
  Object_vptr_0* work = obj->modules->work;
  if (work->slot4(0x20000007) == -1) {
   gfTask* task = findTask(event->id);
   if (task && task->m_taskCategory == gfTask::Category_Weapon) {
    Target* castTask = (Target*)__dynamic_cast(task, 0x3c, lbl_27_data_2D0F0, __RTTI__6gfTask, 0);
    work->slot5(0, 0x20000008);
    if (castTask->check()) {
     switch (*(int*)((u8*)castTask + 0xb8)) {
     case 0x37: work->slot5(1, 0x20000008);
     case 0x33: work->slot5(event->id, 0x20000007); break;
     }
    }
   }
  }
 }
}