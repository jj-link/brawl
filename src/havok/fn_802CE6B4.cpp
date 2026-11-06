#pragma force_active on
extern "C" {
extern char lbl_804873C0[];
extern char lbl_804873E8[];
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

struct Base {
 void* vt;
 Ref* ref;
};

struct Obj {
 void* vt;
 unsigned short type;
 char pad[6];
 Ref* ref0;
 Base base;
};

extern "C" Obj* fn_802CE6B4(Obj* self, int flag) {
 if (self) {
  self->vt = lbl_804873C0;
  Ref* r = self->ref0;
  if (r->active) {
   r->refs = r->refs - 1;
   if (r->refs == 0 && r) r->destroy(1);
  }
  if ((unsigned int)self + 0x10) {
   self->base.vt = lbl_804873E8;
   Ref* r2 = self->base.ref;
   if (r2->active) {
    r2->refs = r2->refs - 1;
    if (r2->refs == 0 && r2) r2->destroy(1);
   }
  }
  if (flag > 0) lbl_805A0EB8->free(self, self->type, 0x25);
 }
 return self;
}
