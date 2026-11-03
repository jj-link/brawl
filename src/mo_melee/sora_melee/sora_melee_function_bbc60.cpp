#include <types.h>
#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_E60[];
void fn_8003DC64(void*, float, void*);
void fn_27_28E48C(void*, void*, float);
}
struct Entry { char pad[4]; void* item; char pad2[8]; unsigned char flags; };
class List { public: virtual void a(); virtual Entry* get(int); virtual void c(); virtual int count(); };
class Posture { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual float lr(); };
struct Param { int kind; unsigned char flag; float value; };
class Work { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual void l(); virtual void m(); virtual void n(); virtual void o(); virtual void p(); virtual void set(int, Param*, int); };
struct Modules { char pad[0xc]; Posture* posture; char pad2[0x44]; Work* work; };
struct Access { char pad[0xd8]; Modules* modules; };
class soNullable { public:
virtual void isNull();
virtual void fn_27_B81C4();
virtual void fn_27_B8360();
virtual void fn_27_B83E4();
virtual void fn_27_B8674();
virtual void fn_27_B86B0();
virtual void fn_27_B87B8();
virtual void fn_27_B88AC();
virtual void fn_27_B8A98();
virtual void fn_27_B8B44();
virtual void fn_27_BC19C();
virtual void fn_27_B91FC();
virtual void fn_27_B86D4();
virtual void fn_27_BE4F0();
virtual unsigned fn_27_B83F4(int);
virtual void fn_27_B8434();
virtual void fn_27_B8468();
virtual void fn_27_B849C();
virtual void fn_27_B84D0();
virtual void fn_27_B8548();
virtual void fn_27_B8594();
virtual void fn_27_B85E0();
virtual void fn_27_BE4E8();
virtual void fn_27_BE4E0();
virtual void fn_27_BE4D8();
virtual void fn_27_B8648();
virtual void fn_27_B8780();
virtual void fn_27_BC0A4();
virtual void fn_27_BC0BC();
virtual void fn_27_B9918();
virtual void fn_27_B9D20();
virtual void fn_27_BA1C8(int, float, float);
virtual void fn_27_BA600();
virtual void fn_27_BA514();
virtual void fn_27_BA594();
virtual void fn_27_BA714();
virtual void fn_27_BA9B8();
virtual void fn_27_BAA38();
virtual void fn_27_BAAAC();
virtual void fn_27_BAB24();
virtual void fn_27_BAC38();
virtual void fn_27_BACD4();
virtual void fn_27_BB040();
virtual void fn_27_BB0C0();
virtual void fn_27_BB14C();
virtual void fn_27_B9108();
virtual void fn_27_B9878();
virtual void fn_27_B97FC();
virtual void fn_27_B9810();
virtual void fn_27_BB658();
virtual void fn_27_BE4D0();
virtual void fn_27_BB398();
virtual void fn_27_BB7B4(int, int, int);
virtual void fn_27_BB24C();
virtual void fn_27_BBA24();
virtual void fn_27_BBACC();
virtual void fn_27_BBC60(unsigned char, float, float);
 char pad[0x34]; List* list38; char pad2[4]; List* list40; char pad3[0x24]; Access* access;
};
struct V2 { float x,y; };
struct V3 { float x,y,z; };
extern "C" void fn_27_BBC60(soNullable* self, unsigned kind, float angle, float speed) {
 const float* values = lbl_27_rodata_E60;
 if (kind == 255) {
   for (unsigned i=0; i<3; i++) self->fn_27_BBC60((unsigned char)i, angle, speed);
 } else if (kind == 2) {
   float lr = self->access->modules->posture->lr();
   Param p; p.kind=0x38; p.flag=0; p.value=lr;
   self->access->modules->work->set(-1, &p, 0);
   if (self->fn_27_B83F4(0)==1 && (unsigned)(self->list38->get(0)->flags & 63)==2)
      self->fn_27_BA1C8(0, values[3], values[0]);
 } else {
   int i=self->list40->count()-1;
   for (; i>=0; --i) {
     if ((self->list40->get(i)->flags & 63)==kind) {
       void* item=self->list40->get(i)->item;
       float lr=self->access->modules->posture->lr();
       V2 v; v.x=speed; v.y=values[0];
       fn_8003DC64(&v, values[1]*angle, &v);
       self->fn_27_BB7B4(i,0,0);
       V3 out; out.y=v.y; out.x=v.x*lr; out.z=values[0];
       fn_27_28E48C(item,&out,lr);
     }
   }
 }
}