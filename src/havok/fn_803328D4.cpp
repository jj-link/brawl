#pragma force_active on
extern "C" {
extern char lbl_80488F50[];
}
class SoHeapAllocator {
public:
 virtual void vf0();
 virtual void vf1();
 virtual void vf2();
 virtual void vf3();
 virtual void vf4();
 virtual void free(void*, unsigned short, int);
};
extern SoHeapAllocator* lbl_805A0EB8;
struct Ref {
 virtual void destroy(int);
 unsigned short active;
 short refs;
};
struct Obj {
 void* vt;
 unsigned short type;
 unsigned short pad;
 Ref* a;
 Ref* b;
 Ref* c;
};
extern "C" Obj* fn_803328D4(Obj* self, int flag) {
 if (self) {
  self->vt = lbl_80488F50;
  Ref* ref = self->a;
  if (ref->active) {
   ref->refs = ref->refs - 1;
   if (ref->refs == 0 && ref != 0) ref->destroy(1);
  }
  ref = self->b;
  if (ref->active) {
   ref->refs = ref->refs - 1;
   if (ref->refs == 0 && ref != 0) ref->destroy(1);
  }
  ref = self->c;
  if (ref->active) {
   ref->refs = ref->refs - 1;
   if (ref->refs == 0 && ref != 0) ref->destroy(1);
  }
  if (flag > 0) lbl_805A0EB8->free(self, self->type, 0x16);
 }
 return self;
}