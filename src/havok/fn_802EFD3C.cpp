#pragma force_active on
#pragma use_lmw_stmw on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
class SoHeapAllocator {
public:
 virtual void vf0();
 virtual void vf1();
 virtual void vf2();
 virtual void vf3();
 virtual void* alloc(int, int);
};
extern SoHeapAllocator* lbl_805A0EB8;
extern "C" char lbl_80487320[];
struct Ref {
 virtual void destroy(int);
 u16 active;
 s16 refs;
 void* a;
 void* b;
 void* c;
 void* d;
};
struct Other { void* a; void* b; };
struct Self { u8 pad[0x68]; Other* other; Ref* ref; };
extern "C" void fn_802EB3FC(Self*, int, int);
extern "C" void fn_802EFD3C(Self* self, Ref* arg, char* flag, int x, int y) {
 if (!arg) {
  Ref* p = (Ref*)lbl_805A0EB8->alloc(0x18, 0x25);
  p->active = 0x18;
  arg = p;
  if (p) {
   p->refs = 1;
   *(void**)p = lbl_80487320;
   p->a = lbl_80487320 + 0x10;
   p->b = lbl_80487320 + 0x20;
   p->c = lbl_80487320 + 0x30;
   p->d = lbl_80487320 + 0x40;
  }
 } else if (arg->active) {
  arg->refs = arg->refs + 1;
 }
 Ref* p = self->ref;
 if (p->active) {
  p->refs = p->refs - 1;
  if (p->refs == 0 && p != 0) p->destroy(1);
 }
 self->ref = arg;
 void* ptr = arg;
 if (arg) ptr = (char*)arg + 0xc;
 char f = *flag;
 self->other->b = ptr;
 if (f) fn_802EB3FC(self, x, y);
}