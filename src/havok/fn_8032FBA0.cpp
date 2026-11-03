#pragma force_active on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern unsigned char lbl_80488E90[];
extern void* lbl_805A0EC8;
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
class Class_8027D01C {
public:
 ~Class_8027D01C();
 char data[16];
};
class Ref {
public:
 virtual ~Ref();
 unsigned short flag;
 short count;
};
struct Array {
 void* data;
 unsigned int size;
 unsigned int raw;
 char first[16];
 bool isOwned() const { return (raw & 0x80000000) == 0; }
 void dealloc() { fn_8027EABC(lbl_805A0EC8, data, raw << 3, 0x15); }
 ~Array() {
  if ((unsigned int)this + 12) ((Class_8027D01C*)first)->~Class_8027D01C();
  if ((unsigned int)this && isOwned()) dealloc();
 }
};
struct Obj {
 void* vtable;
 unsigned short type;
 unsigned short pad;
 Ref* ref;
 Array array;
 Class_8027D01C second;
};
extern "C" Obj* fn_8032FBA0(Obj* self, int flag) {
 if (self) {
  self->vtable = lbl_80488E90;
  Ref* ref = self->ref;
  if (ref->flag && --ref->count == 0) {
   delete ref;
  }
  if ((unsigned int)self + 0x28) self->second.~Class_8027D01C();
  self->array.~Array();
  if (flag > 0) lbl_805A0EB8->free(self, self->type, 0x13);
 }
 return self;
}