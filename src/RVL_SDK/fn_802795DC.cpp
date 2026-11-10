#include <types.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
};
struct Entry { u32 unused; Object_vptr_0* object; };
struct Owner { u8 pad[8]; u8 data[8]; u16 count; };
extern "C" Entry* fn_8015C1EC(void*, u16);
extern "C" void fn_802795DC(Owner* self) {
 for (u32 i = 0; i < self->count; ++i) {
  fn_8015C1EC(self->data, (u16)i)->object->slot2();
 }
}