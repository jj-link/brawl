#include <types.h>
#pragma force_active on
struct Data { u32 a,b,c; };
struct Result { Data data; s16 d,e; };
struct Entry { Result value; char pad[8]; };
class Inner {
public:
 virtual void slot0();
 virtual Entry* slot1(int);
 virtual void slot2();
 virtual void slot3();
 virtual u32 slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 char pad[8];
 Entry entries[1];
};
class Object {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual int slot4();
 char pad[12];
 Inner inner;
 int find(int limit) {
   if (limit <= -1) return slot4()-1;
   for (int i=0; i<slot4(); ++i) {
     s16 value=inner.slot1(i)->value.e;
     if (value <= -1) return i-1;
     if (value > limit) return i-1;
   }
   return slot4()-1;
 }
};
extern "C" int fn_27_C90BC(Inner*, int, int);
extern "C" void fn_27_D8810(Result*, u32*, int, s16*, int);
extern "C" int fn_27_D8228(Object* self, u32* a, int b, s16* c, int d) {
 int pos=self->slot4()-1;
 if (d>=0) pos=self->find(d);
 int idx=fn_27_C90BC(&self->inner,pos,b);
 if (idx>=0) {
  s16 h=*c;
  Result result;
  fn_27_D8810(&result,a,b,&h,d);
  if (self->inner.slot4()!=1U && idx>=0) self->inner.slot13();
  self->inner.entries[idx].value=result;
 }
 return idx;
}