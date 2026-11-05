#include <so/model/so_model_module_simple.h>
#pragma force_active on
#define V(n) virtual void slot##n();
class Query {
public:
V(0)
V(1)
V(2)
V(3)
V(4)
V(5)
V(6)
V(7)
V(8)
V(9)
V(10)
V(11)
V(12)
V(13)
V(14)
V(15)
V(16)
V(17)
V(18)
V(19)
V(20)
V(21)
V(22)
V(23)
V(24)
V(25)
V(26)
V(27)
V(28)
V(29)
V(30)
V(31)
V(32)
V(33)
V(34)
V(35)
V(36)
V(37)
V(38)
V(39)
V(40)
V(41)
V(42)
V(43)
V(44)
V(45)
V(46)
V(47)
V(48)
V(49)
V(50)
V(51)
V(52)
V(53)
V(54)
V(55)
V(56)
V(57)
V(58)
V(59)
V(60)
V(61)
V(62)
V(63)
V(64)
V(65)
V(66)
V(67)
V(68)
V(69)
V(70)
V(71)
V(72)
V(73)
V(74)
V(75)
V(76)
V(77)
virtual u32 flags();
V(79)
V(80)
virtual u32 node();
V(82)
V(83)
V(84)
V(85)
V(86)
V(87)
virtual u32 test1();
virtual u32 test2();
V(90)
V(91)
V(92)
V(93)
V(94)
V(95)
V(96)
V(97)
virtual void matrix(Matrix*, int);
};
struct Modules { char pad[0x54]; Query* query; };
struct Access { char pad[0xD8]; Modules* modules; };
class Model {
public:
 char pad[8];
V(0)
V(1)
V(2)
V(3)
V(4)
V(5)
V(6)
virtual void update();
V(8)
V(9)
V(10)
V(11)
V(12)
V(13)
V(14)
V(15)
V(16)
V(17)
V(18)
V(19)
V(20)
V(21)
V(22)
V(23)
V(24)
V(25)
V(26)
V(27)
V(28)
V(29)
V(30)
V(31)
V(32)
V(33)
virtual u32 convert(u32);
char *scn;
char pad2[0x74];
s32 state;
char pad3[0x20];
signed char* data;
char pad4[0x1c];
Access* access;
};
extern "C" void fn_80047A50(char*, signed char*, unsigned long);
extern Model* lbl_27_bss_28;
extern "C" void fn_27_973C(Model* self) {
 if (lbl_27_bss_28 != self && self->access->modules->query->test1() == 1) {
  if (self->access->modules->query->test2() == 1) lbl_27_bss_28 = self;
  Matrix a(true);
  Matrix b(true);
  self->access->modules->query->matrix(&a, 0);
  lbl_27_bss_28 = 0;
  u32 node = self->convert(self->access->modules->query->node());
  ((soModelModuleSimple*)self)->soModelModuleSimple::getNodeGlobalMtx(node, &b, true);
  float* pa = &a.m[0][0];
  float* pb = &b.m[0][0];
  int i;
  for (i = 0; i < 12; i++) {
   if (pa[i] != pb[i]) break;
  }
  if (i != 12) {
   if (self->access->modules->query->flags() & 0x10) fn_80047A50(self->scn, self->data, node);
   else self->update();
  }
  self->state = -1;
 }
}
