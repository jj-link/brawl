#pragma force_active on
#include <mt/mt_vector.h>
#define S(n) virtual void slot##n();
class soNullable {
public:
 S(0) S(1) S(2) S(3) S(4) S(5) S(6) S(7) S(8) S(9)
 S(10) S(11) S(12) S(13) S(14) S(15) S(16) S(17) S(18) S(19)
};
class Work {
public:
 S(0) S(1) S(2) S(3) S(4) S(5) S(6) S(7) S(8) S(9) S(10) S(11)
 virtual float getFloat(unsigned int);
 S(13) S(14) S(15) S(16)
 virtual unsigned int isFlag(unsigned int);
 virtual void setFlag(unsigned int);
 virtual void clearFlag(unsigned int);
};
class Posture {
public:
 S(0) S(1) S(2) S(3)
 virtual Vec3f getPos();
 S(5) S(6) S(7) S(8) S(9) S(10) S(11) S(12) S(13) S(14) S(15) S(16) S(17) S(18) S(19)
};
struct Modules { char pad[12]; Posture* posture; char pad2[0x54]; Work* work; };
struct Access { char pad[0xd8]; Modules* modules; };
struct Link { char pad[0x1c]; unsigned int id; };
struct Pair { unsigned int x, y; };
struct Target { char pad[0x18]; Pair lower; Pair upper; char pad2[0x1c]; Link* link; unsigned int id; };
struct Self { char pad[0xc]; Target* first; Target* second; char pad2[0x1c]; soNullable output; };
inline unsigned int same(Target* b, Target* a) {
 unsigned int id, link;
 if (!a->link) { link = 0; id = 0; }
 else { id = a->id; link = a->link->id; }
 unsigned int result;
 if (!b->link) result = 0;
 else {
  result = 0;
  if (id == b->id && link == b->link->id) result = 1;
 }
 return result;
}
extern "C" {
 extern void* g_aiMgr;
 extern const float lbl_27_rodata_7C78[];
 void fn_27_388068(Self*, int, int, Access*);
 int fn_27_388920();
 unsigned int fn_27_1ED8A4(void*, Vec3f*, Target**, int, int, float, float, float);
 void fn_27_38851C(Self*, Target*, Vec3f*, Vec2f*, Vec2f*);
 void fn_27_388298(Self*, Access*, float, float, float);
 void fn_27_388B04(Self*, soNullable*, Vec2f*, Target*, Vec2f*, float);
}
extern "C" void fn_27_388674(Self* self, int a, int b, Access* access) {
 const float* constants = lbl_27_rodata_7C78;
 access->modules->work->clearFlag(0x12000040);
 if (access->modules->work->isFlag(0x1200003e) == 1)
  fn_27_388068(self, a, b, access);
 if (fn_27_388920()) {
  Vec3f pos = access->modules->posture->getPos();
  self->output.slot8();
  if (fn_27_1ED8A4(g_aiMgr, &pos, &self->first, 0, -1, constants[18], constants[5], constants[5]) == 1) {
   Pair lower = self->first->lower;
   Pair upper = self->first->upper;
   fn_27_38851C(self, self->first, &pos, (Vec2f*)&lower, (Vec2f*)&upper);
   fn_27_388298(self, access, *(float*)&lower.x, *(float*)&upper.x, constants[19]);
  }
  float y = access->modules->work->getFloat(0x11000014);
  float x = access->modules->work->getFloat(0x11000013);
  Vec3f p(x, y, constants[5]);
  if (fn_27_1ED8A4(g_aiMgr, &p, &self->second, 0, -1, constants[18], constants[5], constants[5]) == 1) {
   if (self->first && self->second) {
    if (same(self->second, self->first) == 1) access->modules->work->setFlag(0x12000040);
   }
   Vec2f center(p.m_x, p.m_y);
   fn_27_388B04(self, &self->output, &center, self->second, (Vec2f*)((char*)self->second + 8), constants[8]);
  }
 }
}