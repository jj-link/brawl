#pragma force_active on
struct Element { int pad; int value; };
class Sub {
public:
 virtual void f2();
 virtual void f3();
 virtual Element* get(int idx);
 virtual int size();
 virtual void f6();
 virtual void f7();
 virtual void f8();
 virtual void f9();
 virtual void f10();
 virtual void f11();
 virtual void f12();
 virtual void f13();
 virtual void f14();
 virtual void f15();
 virtual unsigned int f16();
};
class Owner {
public:
 virtual void f2();
 virtual void f3();
 virtual void f4();
 virtual void f5();
 virtual void f6();
 virtual unsigned int f7();
 char pad[0x0C];
 Sub m_sub;
};
extern "C" int fn_27_F21CC(Owner* self) {
 int prev;
 int r30;
 if (self->m_sub.f16() == 1) return 0x7FFF;
 if (self->f7() == 1) return 0;
 int idx = self->m_sub.size() - 1;
 if (self->m_sub.get(idx)->value < 0x7FFF) {
  idx = self->m_sub.size() - 1;
  return self->m_sub.get(idx)->value + 1;
 }
 r30 = self->m_sub.size() - 1;
 while (r30 >= 0) {
  if (r30 == 0) {
   if (self->m_sub.get(r30)->value == 0) return -1;
   return self->m_sub.get(r30)->value - 1;
  }
  prev = self->m_sub.get(r30 - 1)->value;
  if (self->m_sub.get(r30)->value - 1 > prev) return self->m_sub.get(r30)->value - 1;
  r30 -= 1;
 }
 return -1;
}