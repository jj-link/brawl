#include <types.h>
#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_E60;
extern const float lbl_27_rodata_E64;
void fn_8003DC64(void*, float, void*);
void fn_27_28E48C(void*, void*, float);
}
struct Entry { int kind; void* item; };
class List { public: virtual void a(); virtual Entry* get(int); virtual void c(); virtual int count(); };
class Posture { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual float lr(); };
struct Modules { char pad[0xc]; Posture* posture; };
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
virtual void fn_27_B83F4();
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
virtual void fn_27_BA1C8();
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
char pad[0x3c]; List* list40; char pad2[0x24]; Access* access;
};
struct V2 { float x,y; };
struct V3 { float x,y,z; };
extern "C" void fn_27_BBACC(soNullable* self, int kind, float angle, float speed) {
 void* item;
 int i=self->list40->count()-1;
 for (; i>=0; --i) {
   if (self->list40->get(i)->kind==kind) {
     item=self->list40->get(i)->item;
     float lr=self->access->modules->posture->lr();
     V2 v; v.x=speed; v.y=lbl_27_rodata_E60;
     fn_8003DC64(&v, lbl_27_rodata_E64*angle, &v);
     self->fn_27_BB7B4(i,0,0);
     V3 out; out.y=v.y; out.x=v.x*lr; out.z=lbl_27_rodata_E60;
     fn_27_28E48C(item,&out,lr);
   }
 }
}