#include <types.h>
#pragma force_active on
extern "C" void* fn_8015C1EC(void*, u16);
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual int slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(int, void*); virtual void slot14(); virtual void slot15();
 virtual int slot16(int,int,int,int,int,float,float); virtual int slot17();
};
class Parent {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(int,int,int);
 char pad[4]; char list[8]; u16 count;
};
struct Item { int pad; Object_vptr_0* obj; };
extern "C" int fn_80279400(Parent* self, int a, int b, int c, int d, int e, float x, float y) {
 int result = 0;
 Object_vptr_0* selected = 0;
 unsigned int i = 0;
 while (i < self->count) {
  Item* item = (Item*)fn_8015C1EC(self->list, (u16)i);
  if (item->obj->slot16(a,b,c,d,e,x,y)) {
   if (item->obj->slot17()) selected = item->obj;
   result = 1;
  }
  i++;
 }
 if (selected) {
  if (b) {
   char out[12];
   selected->slot13(b,out);
   self->slot10(selected->slot6(),0,e);
  }
  if (d) {
   char out[12];
   selected->slot13(d,out);
   self->slot10(selected->slot6(),5,e);
  }
 }
 return result;
}