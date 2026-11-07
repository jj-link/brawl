#pragma force_active on
extern "C" unsigned char lbl_8040AA20[];
class Self;
class Object_vptr_0 {
public:
 virtual int slot0(unsigned char**);
 virtual void slot1(unsigned int, int, Self*);
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 void* parent;
};
class Self {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12(Object_vptr_0*);
 char pad[0x134];
 Object_vptr_0* obj;
 char pad2[8];
 unsigned int flags;
};
extern "C" unsigned int fn_8019DA84(Object_vptr_0*, unsigned int);
extern "C" int fn_801AF0C4(Self*, Object_vptr_0*, unsigned int);
extern "C" int fn_801B2EEC(Self* self, Object_vptr_0* obj, int kind) {
 if (obj && !obj->parent) {
 if ((unsigned int)(kind - 5) <= 1) {
  bool ok = false;
  if (obj) {
   unsigned char* t = lbl_8040AA20;
   if (obj->slot0(&t)) ok = true;
  }
  Object_vptr_0* p;
  if (ok) p = obj; else p = 0;
  if (p) {
   if (!fn_8019DA84(p, 4)) return 0;
   if (self->obj) self->slot12(self->obj);
   self->obj = p;
   p->slot1(0x10002, 0, self);
   self->flags &= ~1;
   return 1;
  }
  if (kind == 6) return fn_801AF0C4(self, obj, kind);
  return 0;
 }
 return fn_801AF0C4(self, obj, kind);
 }
 return 0;
}