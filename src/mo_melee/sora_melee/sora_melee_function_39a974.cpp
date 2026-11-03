#pragma force_active on
class soNullable {
public:
 virtual void isNull(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void slot5(int,int); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(float,int);
 virtual void slot14(); virtual void slot15(); virtual void slot16(int,int);
};
struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void processCamera(); virtual void slot12(); virtual void slot13(); virtual void slot14();
 virtual void slot15(); virtual void slot16(); virtual void renderOpa(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void init(); virtual void slot22(); virtual void slot23(); virtual void slot24();
 virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
 virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34();
 virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void fn_27_248088();
 virtual int slot40();
};
struct Modules { char pad[0x64]; soNullable* work; char pad68[0x1c]; soNullable* other; };
struct Access { char pad[8]; gfTask* task; char padC[0xcc]; Modules* modules; };
extern "C" {
 extern signed char lbl_27_bss_8964;
 extern char lbl_27_bss_8968[];
 extern char lbl_27_bss_8958[];
 extern char lbl_27_data_9B790[];
 extern void* __vt__10soNullable;
 extern const float lbl_27_rodata_7DE0;
 void* fn_27_39A934(void*, int);
 void* __register_global_object(void*, void* (*)(void*, int), void*);
 void fn_27_39B438(Access*, int, int, int);
 void fn_27_39B758(Access*);
}
static inline void initGlobal() {
 if (lbl_27_bss_8964 == 0) {
  *(void**)lbl_27_bss_8968 = &__vt__10soNullable;
  *(void**)lbl_27_bss_8968 = lbl_27_data_9B790;
  __register_global_object(lbl_27_bss_8968, fn_27_39A934, lbl_27_bss_8958);
  lbl_27_bss_8964 = 1;
 }
}
extern "C" void fn_27_39A974(void*, Access* arg) {
 int value;
 soNullable* work = arg->modules->work;
 work->slot13(lbl_27_rodata_7DE0, 0x11000013);
 work->slot13(lbl_27_rodata_7DE0, 0x11000014);
 initGlobal();
 fn_27_39B438(arg, 0, 0, 0);
 value = 0;
 if (arg->task->slot40() == 5) { value = 13; }
 arg->modules->other->slot16(value, 0);
 arg->modules->work->slot5(-1, 0x10000042);
 initGlobal();
 fn_27_39B758(arg);
}