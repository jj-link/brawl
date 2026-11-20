#pragma force_active on
struct TaskBase { char pad[0x3c]; };
class TaskObj : public TaskBase { public:
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
 virtual int slot40();
};
class ModA { public:
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
 virtual void slot16(int, int);
};
class WorkModule { public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual int getInt(unsigned int); virtual void setInt(int, unsigned int);
};
extern "C" {
void fn_27_39B438(char*, int, int, int);
void fn_27_39B758(char*);
void* fn_27_39A934(void*, int);
void* __register_global_object(void*, void* (*)(void*, int), void*);
extern signed char lbl_27_bss_8964;
extern char lbl_27_bss_8968[];
extern char lbl_27_bss_8958[];
extern char lbl_27_data_9B790[];
extern void* __vt__10soNullable;
}
static inline void initGlobal() {
 if (!lbl_27_bss_8964) {
  *(void**)lbl_27_bss_8968 = &__vt__10soNullable;
  *(void**)lbl_27_bss_8968 = lbl_27_data_9B790;
  __register_global_object(lbl_27_bss_8968, fn_27_39A934, lbl_27_bss_8958);
  lbl_27_bss_8964 = 1;
 }
}
extern "C" void fn_27_39AB00(void*, char* self) {
 initGlobal();
 fn_27_39B438(self, 0, 0, 0);
 int var = 0;
 TaskObj* task = *(TaskObj**)(self + 0x8);
 if (task->slot40() == 5) var = 13;
 ModA* modA = *(ModA**)(*(char**)(self + 0xd8) + 0x84);
 modA->slot16(var, 0);
 WorkModule* work = *(WorkModule**)(*(char**)(self + 0xd8) + 0x64);
 work->setInt(-1, 0x10000042);
 initGlobal();
 fn_27_39B758(self);
}