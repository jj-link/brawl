#pragma force_active on

struct Object_vptr_4_base { char pad[4]; };
class Object_vptr_4 : public Object_vptr_4_base {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(void*, int, int);
};
struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
 virtual void fn_27_7B274(); virtual void fn_27_7AC18(); virtual void fn_27_7AC28();
 virtual void fn_27_7AB50(); virtual void fn_27_7B2EC(); virtual void fn_27_7AB10();
 virtual void fn_27_7AD2C(); virtual void fn_27_7AEDC(void*);
};
extern "C" {
extern void* lbl_27_bss_F0;
extern Object_vptr_4 lbl_27_bss_71C8;
extern const float lbl_27_rodata_4610;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
void fn_27_4AB8(void*);
}
class V2C34 {
public:
 virtual void a(); virtual void b(); virtual void c(); virtual void d(int, void*);
};
struct Prefix8 { char pad[8]; };
class VE7C : public Prefix8 {
public:
#define V(n) virtual void v##n();
 V(00) V(01) V(02) V(03) V(04) V(05) V(06) V(07)
 V(08) V(09) V(10) V(11) V(12) V(13) V(14) V(15)
 V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23)
 V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31)
 V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
 V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47)
 V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55)
 V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63)
 V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71)
 V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
 V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87)
 V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95)
 V(96) V(97) V(98) V(99) V(100) V(101) V(102) V(103)
 V(104) V(105) V(106) V(107) V(108) V(109) V(110) V(111)
 V(112) V(113) V(114) V(115) V(116) V(117) V(118) V(119)
 V(120) V(121) V(122) V(123) V(124) V(125) V(126)
 virtual void target(int);
#undef V
};
class V15C0 {
public:
#define V(n) virtual void v##n();
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
 V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
 V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
 V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
 V(40) V(41) V(42) V(43) V(44)
 virtual void reset(); virtual float value(); virtual void finish();
#undef V
};
class V2AAC {
public:
#define V(n) virtual void v##n();
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16)
 virtual int flag(int);
#undef V
};
class V297C {
public:
 virtual void a(); virtual void b(); virtual unsigned int* get(int);
};
extern "C" void fn_27_289234(void* object) {
 unsigned char* self = (unsigned char*)object;
 if (self[0x3d5d]) {
  if (!lbl_27_bss_F0) {
   void* p = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
   if (p) p = fn_27_5BCD0(p);
   lbl_27_bss_F0 = p;
  }
  if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
   self[0x3d5d] = 0;
   ((V2C34*)(self + 0x2c34))->d(1, self + 0xcc);
   ((VE7C*)(self + 0xe7c))->target(1);
  }
 }
 fn_27_4AB8(object);
 if (!lbl_27_bss_F0) {
  void* p = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
  if (p) p = fn_27_5BCD0(p);
  lbl_27_bss_F0 = p;
 }
 if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
  *(int*)(self + 0x8e4) = 0;
  *(float*)(self + 0x8e0) = lbl_27_rodata_4610;
  *(int*)(self + 0x3d30) = -1;
  *(int*)(self + 0x3d34) = -1;
  self[0x3d40] = 0;
  self[0x3d41] = 0;
  self[0x2130] = 0;
  if (((V15C0*)(self + 0x15c0))->value() <= lbl_27_rodata_4610 &&
      ((V2AAC*)(self + 0x2aac))->flag(0x22000000) &&
      !(*((V297C*)(self + 0x297c))->get(8) & 0x4c00)) {
   ((Object_vptr_4*)&lbl_27_bss_71C8)->slot5(self + 0xcc, 0xd6f, 0);
   ((V15C0*)(self + 0x15c0))->reset();
   ((Object_vptr_4*)&lbl_27_bss_71C8)->slot5(self + 0xcc, 0xd70, 0);
   ((V15C0*)(self + 0x15c0))->finish();
  }
 }
 (*(Class_90D8**)(self + 0x8d0))->fn_27_7AEDC(object);
}
