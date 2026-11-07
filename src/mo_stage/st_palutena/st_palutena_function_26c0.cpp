#include <mt/mt_prng.h>
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <ec/ec_mgr.h>
#pragma force_active on
#pragma fp_contract off
extern "C" const float lbl_67_rodata_10[];
struct Base { char pad[0x3c]; };
class Object : public Base {
public:
#define V(n) virtual void slot##n();
V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
V(20) V(21) V(22) V(23) V(24) V(25) V(26)
virtual void slot27(unsigned);
V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47)
virtual void slot48(Vec3f*, unsigned, unsigned);
V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)
V(90) V(91) V(92) V(93) V(94) V(95)
virtual void slot96(unsigned, unsigned);
virtual void slot97(unsigned, unsigned);
V(98) V(99) V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109)
V(110) V(111) V(112) V(113) V(114) V(115) V(116)
virtual void slot117();
virtual unsigned char slot118();
#undef V
char pad40[4];
nw4r::g3d::ScnMdl** models;
char pad48[0x24];
unsigned char flags;
char pad6d[0x53];
unsigned index;
unsigned node;
char padc8[0x84];
int active;
char pad150[0xc];
float* frame;
float oldFrame;
char pad164[8];
unsigned char previous;
char pad16d[3];
float value;
char pad174[0x24];
unsigned char type;
unsigned char state;
char pad19a[2];
float timer;
char pad1a0[0x11];
unsigned char enabled;
char pad1b2[0x16];
snd3DGenerator generator;
};
extern "C" void fn_67_26C0(Object* self, float delta) {
 const float* c = lbl_67_rodata_10;
 if (self->enabled == 1) {
  switch (self->slot118()) {
  default:
   self->slot27(0);
   if (self->state == 0) self->slot97(0, 0);
   break;
  case 3:
   if (self->state != 2) self->slot27(0);
   else self->slot27(1);
   break;
  case 1:
  case 2:
   if (self->state != 1) self->slot27(0);
   else self->slot27(1);
   break;
  case 0:
   if (self->state != 0) self->slot27(0);
   else self->slot27(1);
   if (self->state == 0) self->slot96(0, 0);
   break;
  }
  self->timer -= delta;
  if (self->timer < c[0]) self->timer = c[0];
  if (*self->frame < self->oldFrame && (unsigned)((self->flags >> 7) & 1) == 1) {
   self->value = c[2] + c[2] * randf();
   self->generator.playSE((SndID)0x1cde, 0, 0, -1);
   unsigned char state = self->slot118();
   if (self->previous != state && state != 0)
    self->generator.playSE((SndID)0x1cdd, 0, 0, -1);
   self->previous = state;
   if (c[0] == self->timer) {
    Vec3f position;
    self->slot48(&position, self->index, self->node);
    Vec3f zero;
    zero.m_x = c[0]; zero.m_y = c[0]; zero.m_z = c[0];
    unsigned handle = g_ecMgr->setEffect((EfID)0x4f0001, &zero);
    unsigned parent;
    switch (self->type) { case 4: parent = 2; break; default: parent = 1; break; }
    g_ecMgr->setParent(handle, self->models[self->index], parent, false);
    self->timer = c[3] + c[2] * randf();
   }
  }
  self->oldFrame = *self->frame;
 } else {
  if (self->state != 0 || (self->slot117(), self->active != 0))
   self->enabled = 1;
 }
}