#include <types.h>
#pragma force_active on
class Elem { public: int a; int value; };
class Inner {
public:
 virtual void v0(); virtual void v1(); virtual Elem* get(int index); virtual int count();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
 virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
 virtual u32 v14();
};
class Outer {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual u32 v5();
 u8 pad[0xC]; Inner m_inner;
};
extern "C" int fn_27_EFA3C(Outer* self) {
 int prev;
 int i;
 if (self->m_inner.v14() == 1) return 0x7FFF;
 if (self->v5() == 1) return 0;
 int idx = self->m_inner.count() - 1;
 if (self->m_inner.get(idx)->value < 0x7FFF) {
  idx = self->m_inner.count() - 1;
  return self->m_inner.get(idx)->value + 1;
 }
 i = self->m_inner.count() - 1;
 while (i >= 0) {
  if (i == 0) {
   if (self->m_inner.get(i)->value == 0) return -1;
   return self->m_inner.get(i)->value - 1;
  }
  prev = self->m_inner.get(i - 1)->value;
  int cur = self->m_inner.get(i)->value - 1;
  if (cur > prev) return self->m_inner.get(i)->value - 1;
  i--;
 }
 return -1;
}