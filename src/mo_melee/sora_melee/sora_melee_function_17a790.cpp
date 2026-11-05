#include <so/so_value_accesser.h>
#include <gf/gf_task.h>
#pragma force_active on
typedef unsigned int uint;
#include <mt/mt_vector.h>
#define V(n) virtual void v##n();
#define TEN(n) V(n##0) V(n##1) V(n##2) V(n##3) V(n##4) V(n##5) V(n##6) V(n##7) V(n##8) V(n##9)
class Interface {
public:
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
 V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
 V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
 V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41)
 virtual int v42(int);
};
class Posture {
public:
 V(0) V(1) V(2) V(3)
 virtual Vec3f get();
 virtual void set(const Vec3f&);
};
class Mod40 {
public:
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16)
 virtual void v17(int);
};
class Mod64 {
public:
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16)
 virtual int v17(int);
 V(18)
 virtual void v19(int);
};
class Mod20 {
public:
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12)
 virtual void v13(void*,int);
};
class Mod58 {
public:
 V(0) V(1) V(2) V(3) V(4) V(5) V(6)
 virtual void v7(int);
};
class Mod14 {
public:
 V(0) V(1) V(2) V(3) V(4) V(5)
 virtual void v6(int,int);
};
class Mod10 {
 char pad[8];
public:
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10)
 virtual void v11(int);
 V(12) V(13) V(14) V(15) V(16) V(17) V(18)
 virtual void v19(int,int);
 V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34)
 virtual Vec3f v35(int);
 V(36) V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54)
 virtual unsigned int v55(int,int);
 V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99) V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109) V(110) V(111)
 virtual void v112(int);
 V(113) V(114) V(115) V(116) V(117) V(118)
 virtual void v119(int);
};
class Other {
 char pad[8];
public:
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88)
 virtual unsigned int v89(Vec3f*,Vec3f*,int);
};
class Task : public gfTask {
public:
 V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41) V(42)
 virtual void v43();
};
struct Modules {
 char pad0[12]; Posture* posture; Mod10* m10; Mod14* m14;
 char pad18[8]; Mod20* m20; char pad24[0x1c]; Mod40* m40;
 char pad44[0x10]; Interface* m54; Mod58* m58; char pad5c[8]; Mod64* m64;
};
struct Object { char pad[8]; Task* task; char padc[0xcc]; Modules* modules; };
extern "C" void* __dynamic_cast(void*,long,const void*,const void*,short);
extern "C" Other* fn_27_8CDC4(void*);
extern const char lbl_27_data_248[];
extern char __RTTI__6gfTask[];
extern "C" void fn_27_17A790(void*, Object* self, int type) {
 unsigned int changed = 0;
 if (type == 0x50) {
  Other* other = fn_27_8CDC4(__dynamic_cast(gfTask::getTask(self->modules->m54->v42(0)),0x3c,lbl_27_data_248,__RTTI__6gfTask,0));
  Vec3f pos = self->modules->posture->get();
  Vec3f tmp;
  if (other->v89(&pos,&tmp,0) == 1) {
   self->modules->posture->set(pos);
   changed = 1;
  }
 }
 self->modules->m40->v17(0);
 if (changed == 1) {
  self->task->v43();
  self->modules->m10->v11(1);
  self->modules->m10->v119(0);
  Vec3f pos = self->modules->m10->v35(0);
  self->modules->posture->set(pos);
  self->modules->m10->v112(0);
  if (self->modules->m10->v55(8,0) == 1) {
   pos = self->modules->m10->v35(0);
   self->modules->posture->set(pos);
   self->modules->m10->v19(1,0);
   self->modules->m14->v6(0,0);
  }
 }
 if (self->modules->m64->v17(0x1200003b)) {
  self->modules->m64->v19(0x1200003b);
  changed = (unsigned int)self->modules->m20;
  ((Mod20*)changed)->v13(soValueAccesser::getConstantIndefinite((soModuleAccesser*)self,0xa803,0),0);
  self->modules->m58->v7(1);
 }
}