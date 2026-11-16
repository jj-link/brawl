#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(f32);
};
extern f32 lbl_805A23E4;
extern f32 lbl_805A23C0;
extern "C" int fn_800B5854(void*, int, int, int, int);
extern "C" void fn_800B6838(MuObject*, const Vec3f*);
extern "C" void fn_800E1840(void*, u32, int);
extern "C" void fn_800E3A90(u8* self) {
 u8* p;
 u8* pos;
 s32 i;
 i = 2;
 p = self + 8;
 do {
  fn_800B5854(*(MuObject**)(p + 0x28), 0, 0x10, 0, 0);
  i++; p += 4;
 } while (i < 6);
 p = self;
 pos = self + 0xFC;
 short n = 0;
 while (n < 4) {
  fn_800B6838(*(MuObject**)(p + 0x30), (const Vec3f*)pos);
  n++; pos += 0xC; p += 4;
 }
 if (*(u32*)(self + 0x1C) != *(u32*)(self + 0x18)) {
  p = self + 8;
  i = 2;
  do {
   (*(MuObject**)(p + 0x28))->setFrameNode(lbl_805A23E4);
   i++; p += 4;
  } while (i < 6);
  p = self + 8;
  i = 2;
  do {
   ((Object_vptr_0*)(*(char**)(*(char**)(*(char**)(p + 0x28) + 0x14) + 0xC)))->slot8(lbl_805A23C0);
   i++; p += 4;
  } while (i < 6);
 }
 fn_800E1840(self, *(u32*)(self + 0x18), 0);
}