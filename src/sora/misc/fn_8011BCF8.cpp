#include <types.h>
#pragma force_active on
struct Pair { float x, y; };
union Result { u64 bits; Pair value; };
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual u64 slot9(); virtual u64 slot10(); virtual u64 slot11(); virtual u64 slot12();
};
struct Inner { char pad[0x10]; u8 flags; };
struct Dest { char pad[0x84]; float x, y; };
struct Outer {
 char pad0[0x18]; Dest* dest;
 char pad1[0xf4-0x1c]; u8 mode;
 char pad2[0xfc-0xf5]; Inner* inner; void* p100; void* p104;
 char pad3[0x2bc-0x108]; Object_vptr_0* object;
 bool first() { return inner && p100; }
 bool valid() { return first() && p104; }
};
extern "C" int fn_8011BCF8(Outer* self) {
 int result = 0;
 if (self->valid()) {
  Dest* dest = self->dest;
  if ((self->inner->flags >> 3) & 1) {
   switch (self->mode) {
   case 0: { Result r; r.bits = self->object->slot12(); dest->x = r.value.x; dest->y = r.value.y; break; }
   case 1: { Result r; r.bits = self->object->slot10(); dest->x = r.value.x; dest->y = r.value.y; break; }
   case 2: { Result r; r.bits = self->object->slot11(); dest->x = r.value.x; dest->y = r.value.y; break; }
   case 3:
   default: { Result r; r.bits = self->object->slot9(); dest->x = r.value.x; dest->y = r.value.y; break; }
   }
   result = 1;
  }
 }
 return result;
}