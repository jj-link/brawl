#pragma force_active on
struct Range { float a,b,c,d; };
struct Obj;
class Class_80488608 {
public:
 virtual void fn_802F0AE4();
 virtual void fn_80080A64();
 virtual void fn_802F073C();
 virtual void fn_802F0758(Obj*, Range*);
};
struct Inner { char pad[0x10]; Range range; };
struct Obj { char pad[0x4c]; Class_80488608* v; char pad2[0x18]; Inner* inner; char pad3[0x104]; Range range; };
struct Self { char pad[8]; Obj* obj; int fieldC; char pad2[4]; float time; float delta; char pad3[8]; int flag; };
struct Heap { char pad[4]; int flag; int size; char pad2[8]; int a; char pad3[0x10]; int b; };
struct Other { char pad[0x10]; int a; char pad2[8]; int b; };
extern "C" {
extern Heap* lbl_805A0EB8;
extern Other* lbl_805A0EC8;
extern const float lbl_805A44F8, lbl_805A4504;
int fn_802EFF34(Obj*);
void fn_802F1FB4(Self*, Range*);
int fn_802F0C48(Self* self, float delta) {
 self->delta = delta;
 int n = fn_802EFF34(self->obj);
 if (n > lbl_805A0EC8->b - lbl_805A0EC8->a - 16) {
   int sum = lbl_805A0EB8->b + lbl_805A0EB8->a;
   int remaining = lbl_805A0EB8->size <= sum ? 0 : lbl_805A0EB8->size - sum;
   if (n > remaining) {
      lbl_805A0EB8->flag = 1;
      self->flag = 1;
      return 1;
   }
 }
 __declspec(align(16)) Range r;
 float start = self->time;
 float end = start + self->delta;
 r.a = start;
 r.b = end;
 r.c = end - start;
 r.d = lbl_805A44F8 == r.c ? lbl_805A44F8 : lbl_805A4504 / r.c;
 self->obj->range = r;
 self->obj->inner->range = r;
 self->obj->v->fn_802F0758(self->obj, &r);
 fn_802F1FB4(self, &r);
 self->fieldC = 0;
 self->flag = 0;
 return 0;
}
}