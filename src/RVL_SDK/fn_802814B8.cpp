#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(int);
 virtual void slot1();
 virtual void slot2();
 virtual void slot3(void*);
 virtual void slot4();
 virtual void slot5(void*, unsigned short, int);
 unsigned short active;
 short count;
};
class Class_804864A0 {
public:
 virtual void fn_802814B8();
 virtual void fn_80080A64();
 virtual void fn_80281744();
 virtual void fn_80281640();
 virtual void fn_802816FC();
 virtual void fn_802817A4();
 unsigned short type;
 unsigned short pad6;
 Object_vptr_0* ref;
 void* allocation;
 char pad10[8];
 signed char owned;
};
extern char lbl_80486498[];
extern Object_vptr_0* lbl_805A0EB8;
extern "C" Class_804864A0* fn_802814B8(Class_804864A0* self, int flag) {
 if (self) {
  *(void**)self = lbl_80486498;
  self->fn_802816FC();
  Object_vptr_0* ref = self->ref;
  if (ref) {
   if (ref->active != 0) {
    ref->count = ref->count - 1;
    if (ref->count == 0 && ref != 0) ref->slot0(1);
   }
  }
  if (self->owned != 0) lbl_805A0EB8->slot3(self->allocation);
  if (flag > 0) lbl_805A0EB8->slot5(self, self->type, 0x18);
 }
 return self;
}