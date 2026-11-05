#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on
#define VF(n) virtual void f##n();

struct Event { int id; bool flag; Vec3f pos; Event(const Vec3f& v):id(0x836),flag(false),pos(v) {} };
struct SmallEvent { int id; bool flag; SmallEvent():id(0x83c),flag(false) {} };
struct Link {
 VF(0) VF(1) VF(2) VF(3) VF(4) VF(5) VF(6) VF(7) VF(8) VF(9) VF(10) VF(11) VF(12) VF(13) VF(14)
 virtual void f15(int, void*);
};
struct Prefix { int a,b; };
struct Physics : Prefix {
 VF(0) VF(1) VF(2) VF(3) VF(4) VF(5) VF(6) VF(7) VF(8) VF(9)
 VF(10) VF(11) VF(12) VF(13) VF(14) VF(15) VF(16) VF(17) VF(18) VF(19)
 VF(20) VF(21) VF(22) VF(23) VF(24) VF(25) VF(26) VF(27) VF(28) VF(29) VF(30) VF(31)
 virtual int f32();
 VF(33) VF(34) VF(35) VF(36) VF(37) VF(38) VF(39) VF(40) VF(41) VF(42)
 virtual void f43(int);
 VF(44) VF(45) VF(46) VF(47) VF(48)
 virtual void f49(int, Vec3f*);
};
struct Holder {
 VF(0) VF(1) VF(2) VF(3)
 virtual int f4(unsigned);
};
struct Mid { char pad[0x54]; Link* link; char pad2[0xc]; Holder* holder; char pad3[0x34]; Physics* physics; };
struct Owner { char pad[0xd8]; Mid* mid; };
extern const float lbl_27_rodata_2B30;
extern "C" void fn_27_1DDF64(void*, Owner* obj) {
 Event ev(Vec3f(lbl_27_rodata_2B30,lbl_27_rodata_2B30,lbl_27_rodata_2B30));
 obj->mid->link->f15(3,&ev);
 if (ev.flag) obj->mid->physics->f49(0,&ev.pos);
 int n=obj->mid->physics->f32();
 if (n<=0) {
  SmallEvent ev2;
  obj->mid->link->f15(1,&ev2);
 } else {
  int v=obj->mid->holder->f4(0x20000001);
  if (v<=0) v=1;
  else if (v>n) v=n;
  obj->mid->physics->f43(v);
 }
}