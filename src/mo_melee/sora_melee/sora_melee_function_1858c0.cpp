#pragma force_active on
struct Vec2 { unsigned int x, y; };
struct Vec3 { float x, y, z; };
struct Flag { int value; bool flag; };
#define V(n) virtual void slot##n();
class soNullable {
public:
 V(0) V(1) V(2) V(3) V(4) V(5) V(6)
 virtual void slot7(int);
 virtual void slot8(int);
 virtual int slot9(int);
 virtual void slot10(); V(11) V(12)
 virtual void slot13(int, float);
 V(14)
 virtual void slot15(int, Flag*);
 V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25)
 virtual void slot26(int);
 V(27) V(28) V(29) V(30) V(31) V(32)
 virtual void slot33(int);
 V(34) V(35) V(36) V(37) V(38) V(39)
 virtual float slot40(int);
 virtual Vec2 slot41(int);
 V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
 V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
 V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
 V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
 V(80) V(81) V(82) V(83) V(84)
 virtual void slot85(Vec3*, Vec3*);
 V(86)
 virtual void slot87(int);
};
class Position {
public:
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
 virtual void slot10(float);
 V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18)
 virtual void slot19();
};
struct OwnerBase { char pad[0x3c]; };
class Owner : public OwnerBase {
public:
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
 V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
 V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
 V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
 V(40) V(41) V(42) V(43)
};
#undef V
struct Modules {
 char pad0[0xc]; Position* pos;
 char pad1[0x10]; soNullable* p20;
 char pad2[0x30]; soNullable* p54;
 soNullable* p58; char pad3[8]; soNullable* p64;
 char pad4[0x20]; soNullable* p88;
};
struct Fighter { char pad0[8]; Owner* owner; char pad1[0xcc]; Modules* modules; };
extern const float lbl_27_rodata_24A8;
extern "C" void fn_27_1858C0(void*, Fighter* f, int arg) {
 if (f->modules->p54->slot9(0)) {
  Flag flag; flag.value = 0x19; flag.flag = false;
  if (arg == 0xd4) {
   Vec2 v; v = f->modules->p54->slot41(0);
   f->modules->p64->slot13(0x21000005, *(float*)&v.x);
   f->modules->p64->slot13(0x21000006, *(float*)&v.y);
   f->modules->pos->slot10(-f->modules->p54->slot40(0));
   f->modules->pos->slot19();
   f->owner->slot43();
   Vec3 b;
   Vec3 a;
   a.x = lbl_27_rodata_24A8; a.y = lbl_27_rodata_24A8; a.z = lbl_27_rodata_24A8;
   b.x = lbl_27_rodata_24A8; b.y = lbl_27_rodata_24A8; b.z = lbl_27_rodata_24A8;
   f->modules->p54->slot85(&b, &a);
  }
  f->modules->p54->slot87(1);
  f->modules->p54->slot15(0, &flag);
 }
 if (f->modules->p54->slot9(0))
  f->modules->p54->slot8(0);
 f->modules->p20->slot26(0);
 f->modules->p58->slot7(1);
 f->modules->p88->slot33(1);
}