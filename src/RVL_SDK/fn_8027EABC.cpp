#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(void*, int, int); virtual void slot6(); virtual void slot7(void*, int, int);
};
struct Self {
 char pad[4]; Object_vptr_0* delegate; char pad2[0x1c]; int max;
 void* heads[17]; int counts[17]; char pad3[0x44]; signed char indices[0x204]; int large[8];
};
extern "C" void fn_8027EABC(Self* self, void* out, int idx, int arg) {
 int count;
 Self* entry;
 int max;
 if (idx <= 0x2000 && (max = self->max) != 0) {
  if (idx <= 0x200) idx = self->indices[idx];
  else idx = self->large[(idx - 1) >> 10];
  entry = (Self*)((char*)self + idx * 4);
  count = entry->counts[0];
  if (count < max) {
   entry->counts[0] = count + 1;
   *(void**)out = entry->heads[0];
   entry->heads[0] = out;
   return;
  }
  self->delegate->slot7(out, idx, arg);
  return;
 }
 self->delegate->slot5(out, idx, arg);
}