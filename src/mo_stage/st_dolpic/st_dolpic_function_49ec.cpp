#pragma force_active on
#include <gr/ground.h>
struct Base { char pad[0x3c]; };
struct Fn : Base {
#define V(n) virtual void f##n();
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
 V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
 V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
 V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
 V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47)
#undef V
 virtual void b(void*, int, unsigned int);
 virtual void unused();
 virtual void a(void*, int, unsigned int);
 char pad1[0x130]; unsigned int countB, countA; char pad2[8];
 unsigned int valsB[0x24]; unsigned int valsA[0xf];
};
extern "C" void fn_46_49EC(Fn* self) {
 ((Ground*)self)->Ground::processAnim();
 if (self->countA) for (unsigned int i=0; i<15; i++)
  self->a((void*)(self->countA+(unsigned char)i*0x30),0,self->valsA[(unsigned char)i]);
 if (self->countB) for (unsigned int i=0; i<36; i++)
  self->b((void*)(self->countB+(unsigned char)i*0xc),0,self->valsB[(unsigned char)i]);
}