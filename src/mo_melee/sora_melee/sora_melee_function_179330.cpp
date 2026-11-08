#include <cm/cm_camera_controller.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on
#pragma fp_contract off
struct Pair { float x, y; };
struct Position { float x, y, z; };
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual Position slot4(); virtual void slot5(); virtual void slot6(int,int); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual unsigned long long slot13(short*);
};
class Module10 {
 int pad[2];
public:
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
 virtual void slot19(int, int);
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
 virtual void slot43(int, int);
};
struct Modules { char pad[0xc]; Object_vptr_0* posture; Module10* status; Object_vptr_0* situation; char pad18[0x64]; Object_vptr_0* kinetic; };
struct Actor { char pad[0xd8]; Modules* modules; };
extern float lbl_27_rodata_233C;
extern float lbl_27_rodata_2340;
inline Pair toPair(unsigned long long n) { return *(Pair*)&n; }
inline bool aboveCamera(const Position& pos) {
  float top = *(float*)((char*)CameraController::getInstance() + 0x160);
  float bottom = *(float*)((char*)CameraController::getInstance() + 0x150);
  bool above = false;
  float limit = bottom + lbl_27_rodata_2340 * nw4r::ut::Abs(top - bottom);
  if (pos.y > limit) above = true;
  return above;
}
extern "C" void fn_27_179330(void*, Actor* a) {
 a->modules->status->slot43(1,0);
 short id = 1;
 Pair speed = toPair(a->modules->kinetic->slot13(&id));
 if (speed.y < lbl_27_rodata_233C) {
  if (aboveCamera(a->modules->posture->slot4())) {
   a->modules->status->slot19(0,0);
   a->modules->situation->slot6(2,0);
  } else {
   a->modules->status->slot19(5,0);
  }
 }
}