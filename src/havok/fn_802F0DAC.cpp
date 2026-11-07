#pragma force_active on
struct Range { float a,b,c,d; };
struct Owner { char pad[0x13c]; int flag; };
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(Range*);
 char pad[4]; Owner* obj; int fieldC; char pad2[4]; float time; float delta; char pad3[8]; int flag;
};
struct Heap { char pad[4]; int flag; };
struct Entry { const char* name; unsigned int time; int unused; };
struct Monitor { int unused; Entry* current; int unused2; Entry* end; };
extern "C" {
extern Heap* lbl_805A0EB8;
extern Monitor lbl_80532448;
extern char lbl_80414030[];
extern const float lbl_805A44F8, lbl_805A4504;
int fn_802F0F4C(Object_vptr_0*);
void fn_802F4D24(Owner*, Range*);
int fn_802F0DAC(Object_vptr_0* self) {
 if (self->flag) return fn_802F0F4C(self);
 __declspec(align(16)) Range r;
 float start = self->time;
 float end = start + self->delta;
 r.a = start;
 r.b = end;
 r.c = end - start;
 r.d = lbl_805A44F8 == r.c ? lbl_805A44F8 : lbl_805A4504 / r.c;
 self->slot12(&r);
 if (lbl_805A0EB8->flag == 1) { self->flag = 2; return 2; }
 self->time += self->delta;
 if (self->obj->flag) {
  signed char test = lbl_80532448.end > lbl_80532448.current;
  if (((unsigned int)(-test | test) >> 31) != 0) {
   Entry* current = lbl_80532448.current;
   current->name = lbl_80414030;
   register unsigned int t; asm { mftb t }
   current->time = t;
   lbl_80532448.current = current + 1;
  }
  fn_802F4D24(self->obj, &r);
  signed char test2 = lbl_80532448.end > lbl_80532448.current;
  if (((unsigned int)(-test2 | test2) >> 31) != 0) {
   Entry* current = lbl_80532448.current;
   current->name = lbl_80414030 + 0x10;
   register unsigned int t; asm { mftb t }
   current->time = t;
   lbl_80532448.current = current + 1;
  }
 }
 self->fieldC = 1;
 self->flag = 0;
 return 0;
}
}