#include <mt/mt_vector.h>
#pragma force_active on
class Fighter;
class Class_9C3C { public:
virtual void fn_107_8720(); virtual void fn_107_160EC(); virtual void fn_107_166C8(); virtual void fn_107_166C4(int, Fighter*); virtual void fn_107_166C0(); virtual void fn_107_166BC(); virtual void fn_107_166B4(); virtual void fn_107_166FC(); virtual void fn_107_166F4(); virtual void fn_107_166EC(); virtual void fn_107_166E4(); virtual void fn_107_166DC(); virtual void fn_107_16674(); virtual void fn_107_166A8(); virtual void fn_107_1669C(); virtual void fn_107_16694(); virtual int getStatusKind();
};
class Class_9E14 { public:
virtual void fn_107_8720(); virtual void fn_107_16090(); virtual void fn_107_168B4(); virtual void fn_107_168AC(); virtual Vec3f fn_107_168A4(); virtual void fn_107_1689C(); virtual void fn_107_16894(); virtual void fn_107_1688C(); virtual void fn_107_16884(); virtual void fn_107_1687C(); virtual void fn_107_16874(); virtual void fn_107_1686C(); virtual void fn_107_16864(); virtual void fn_107_1685C(); virtual void fn_107_1680C(); virtual void fn_107_16854(); virtual void fn_107_16844();
};
struct PointStorage { Vec3f value; unsigned char padding[4]; };
struct soModuleAccesser { unsigned char padding[0x0C]; Class_9E14* postureModule; unsigned char padding2[0x60]; Class_9C3C* statusModule; };
struct Fighter { unsigned char padding[0xD8]; soModuleAccesser* accesser; };
extern "C" unsigned int fn_107_13FB4(void*, Fighter*, Vec3f*);
extern "C" float fn_107_14030(void*, Fighter*, Vec3f*);
extern "C" void fn_107_14404(void* process, Fighter* fighter) {
 int status = fighter->accesser->statusModule->getStatusKind();
 switch (status) {
 case 0x12D: {
  PointStorage point;
  if (fn_107_13FB4(process, fighter, &point.value) == 1) {
   float value = fn_107_14030(process, fighter, &point.value);
   const Vec3f previous = fighter->accesser->postureModule->fn_107_168A4();
   if (previous.m_y < value) fighter->accesser->statusModule->fn_107_166C4(0x12E, fighter);
  }
  break;
 }
 case 0x12E: {
  PointStorage point;
  if (fn_107_13FB4(process, fighter, &point.value) == 1) {
   Vec3f previous = fighter->accesser->postureModule->fn_107_168A4();
   float value = fn_107_14030(process, fighter, &point.value);
   if (previous.m_y > value) fighter->accesser->statusModule->fn_107_166C4(0x12F, fighter);
  }
  break;
 }
 }
}