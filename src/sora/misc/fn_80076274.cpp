#include <types.h>
#include <nw4r/snd/snd_SoundArchive.h>
#pragma force_active on
extern const f32 lbl_805A1AC8;
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(s32); virtual void slot5(); virtual void slot6(); virtual void slot7(s32);
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(s32, f32);
};
struct Entry {
 Object_vptr_0* object; int id; int unk8; u32 handle; int unk10; int priority; int curPriority; u16 count; u16 unk1E;
 bool active() const { return handle != (u32)-1 && count != 0; }
 bool present() const { if (active()) return true; return object != 0; }
};
struct System {
 char pad[0x2D4]; Entry entries[32]; char pad6D4[0x6E0 - 0x6D4]; Object_vptr_0* obj6E0;
 char pad6E4[0x6EF - 0x6E4]; u8 enabled; char pad6F0[0x700 - 0x6F0];
 f32 f700, f704, f708, f70C, f710, f714, f718;
 char pad71C[0xBAC - 0x71C]; int unkBAC; int unkBB0; int ids[6];
 u32 index(int id) {
  if (id == -1) return -1;
  bool valid = false; u32 slot = (u8)id; Entry* entry = &entries[slot];
  if (entry->id == id) { if (entry->present()) valid = true; }
  return valid ? slot : (u32)-1;
 }
};
extern "C" int fn_801CBFB0(void*, void*, int, int, int, int);
extern "C" void fn_801BD4A4(void*, int, f32);
extern "C" int fn_801C6BDC(System*, u32, nw4r::snd::SoundArchive::SoundInfo*);
extern "C" void fn_80076274(System* self) {
 if (!self->enabled) return;
 int id = self->unkBB0;
 if (id != -1) {
  u32 slot = self->index(id);
  if (slot != 0xFFFFFFFFu) {
   self->entries[slot].count = self->entries[slot].count - 1;
   if (self->entries[slot].object) self->entries[slot].object->slot4(0x2D);
   self->entries[slot].handle = 0xFFFFFFFFu;
   self->entries[slot].id = -1;
  }
  self->unkBAC = 0; self->unkBB0 = -1;
 }
 u32 i = 1;
 for (; i < 6; i++) {
  int cur = self->ids[i];
  if (cur != -1) {
   u32 s2 = self->index(cur); self->ids[i] = -1;
   if (s2 != 0xFFFFFFFFu) {
    Entry* entry = &self->entries[s2];
    int handle = (int)self->entries[s2].handle;
    self->unkBAC = self->entries[s2].unk10; self->unkBB0 = self->entries[s2].id;
    if (fn_801CBFB0((char*)self + 0x198, &entry->object, handle, 0, 0, 0) == 0) {
     if (entry->object) entry->object->slot7(0x2D);
     f32 s = self->f70C * self->f718;
     if (entry->object) entry->object->slot12(0, s);
     f32 v = self->f710;
     if (entry->object) fn_801BD4A4(entry->object, 0, v);
     int prio;
     if (!self->enabled) prio = 0x40;
     else {
      nw4r::snd::SoundArchive::SoundInfo info;
      if (fn_801C6BDC(self, (u32)handle, &info)) prio = info.playerPriority;
      else prio = 0x40;
     }
     self->entries[s2].priority = prio; self->entries[s2].curPriority = prio;
    }
    break;
   }
  }
 }
 if (i >= 6) {
  if (self->enabled) {
   self->f704 = lbl_805A1AC8;
   if (self->obj6E0 != 0) {
    f32 f = self->f714 * (lbl_805A1AC8 * (self->f700 * self->f708));
    if (self->obj6E0 != 0) self->obj6E0->slot12(0x2D, f);
   }
  }
 }
}
