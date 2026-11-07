#pragma force_active on
class Class_CF88 {
public:
 virtual void fn_94_6CF8();
 virtual void fn_94_1CAF0();
 virtual void fn_94_1DAE0();
 virtual void fn_94_1DAD8();
 virtual void fn_94_1DAD0();
 virtual void fn_94_1DAC8();
 virtual void fn_94_1DAC0();
 virtual void fn_94_1DAB8();
 virtual void fn_94_1DAB0();
 virtual void fn_94_1DAA8();
 virtual void fn_94_1DAA0();
 virtual void fn_94_1DA98();
 virtual void fn_94_1DA90();
 virtual void fn_94_1DA88();
 virtual void fn_94_1DA38();
 virtual void fn_94_1DA80();
 virtual void fn_94_1DA70();
 virtual int fn_94_1DA60(int);
 virtual void fn_94_1DA50();
 virtual void fn_94_1DA40(int);
};
class MotionModule {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
 virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual void setRate(float);
};
extern "C" {
extern void* g_ftManager;
extern const float lbl_94_rodata_C;
int fn_27_10A4B0(void*, int);
int fn_27_10AA8C(void*, int, int);
void fn_27_10C0DC(void*, int, unsigned char, bool, bool);
void fn_27_130D64(void*);
void fn_94_9134(void* self) {
 void* accesser = *(void**)((char*)self + 0x60);
 Class_CF88* work = *(Class_CF88**)((char*)*(void**)((char*)accesser + 0xd8) + 0x64);
 if (work->fn_94_1DA60(0x1200003d)) {
  work->fn_94_1DA40(0x1200003d);
  if ((unsigned char)fn_27_10A4B0(g_ftManager, *(int*)((char*)self + 0x10c)) > 1) {
   int enabled = fn_27_10AA8C(g_ftManager, *(int*)((char*)self + 0x10c), *(int*)((char*)self + 0x28));
   MotionModule* motion = *(MotionModule**)((char*)*(void**)((char*)accesser + 0xd8) + 8);
   motion->setRate(lbl_94_rodata_C);
   fn_27_10C0DC(g_ftManager, *(int*)((char*)self + 0x10c), !(unsigned char)enabled, 0, 0);
  }
 }
 fn_27_130D64(self);
}
}