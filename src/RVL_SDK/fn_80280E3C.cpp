#pragma force_active on
extern "C" {
extern char lbl_80486460[];
void fn_80280D64(void*, int);
}
class Object_vptr_0 {
public:
 virtual void slot0(int);
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 unsigned short active;
 short refs;
};
class Allocator {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5(void*, unsigned short, int);
};
extern Allocator* lbl_805A0EB8;
struct Obj {
 void* vt;
 unsigned short type;
 unsigned short pad;
 Object_vptr_0* ref;
 char member[12];
};
extern "C" Obj* fn_80280E3C(Obj* self, int flag) {
 if (self) {
  self->vt = lbl_80486460;
  Object_vptr_0* ref = self->ref;
  if (ref->active) {
   ref->refs = ref->refs - 1;
   if (ref->refs == 0 && ref != 0) ref->slot0(1);
  }
  fn_80280D64(self->member, -1);
  if (flag > 0) lbl_805A0EB8->slot5(self, self->type, 0x18);
 }
 return self;
}