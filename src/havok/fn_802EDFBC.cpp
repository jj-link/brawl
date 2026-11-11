#pragma force_active on
#pragma opt_common_subs off
#include <types.h>
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 u16 field_4; int field_8;
};
struct Message { s8 type; char pad[3]; Object_vptr_0* object; };
struct Context { char pad[0x78]; int pending; int refcount; int other; s8 active; char pad2[0x47]; Object_vptr_0** entries; int count; };
inline int findObject(Context* self, Object_vptr_0* object) {
 for (int i = 0; i < self->count; ++i) {
  if (self->entries[i] == object) return i;
 }
 return -1;
}
extern "C" void fn_802EFF2C(Context*, Message*);
extern "C" void fn_802F3F70(Context*, Object_vptr_0*);
extern "C" void fn_802E8498(Object_vptr_0*);
extern "C" void fn_802F86E4(Context*, Object_vptr_0*);
extern "C" void fn_802F0668(Object_vptr_0*);
extern "C" void fn_802EFE70(Context*);
extern "C" void fn_802EDFBC(Context* self, Object_vptr_0* object) {
 if (((const s32*)self)[0x7C / 4] + self->other != 0) {
  Message msg; msg.type = 0xE; msg.object = object; fn_802EFF2C(self, &msg);
 } else {
  self->refcount = self->refcount + 1;
  fn_802F3F70(self, object); fn_802E8498(object); fn_802F86E4(self, object);
  int index = findObject(self, object);
  self->count = self->count - 1; self->entries[index] = self->entries[self->count];
  object->field_8 = 0;
  if (object->field_4 == 0) object->slot11();
  fn_802F0668(object);
  self->refcount--;
  if (self->refcount == 0 && self->pending != 0 && self->active == 0) fn_802EFE70(self);
 }
}
