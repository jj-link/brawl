#include <types.h>
#pragma force_active on
extern const float lbl_27_rodata_4610;
class A {
public:
 virtual void v0(); virtual void v1();
 virtual u32* v4(int);
};
class B {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v6(int, void*, float);
 virtual void v7();
 virtual void v8(float, int, void*, int);
};
class C {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void* v4(u32);
};
class D {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); 
 virtual void v7(void*, int, int, int);
};
struct Outer {
 char pad0[0x25a0]; D d;
 char pad1[0x297c-0x25a4]; A a;
 char pad2[0x2aac-0x2980]; C c;
 char pad3[0x33d0-0x2ab0]; B b;
};
extern "C" void fn_27_289104(Outer* self) {
 int n = -1;
 u32 flags = *self->a.v4(8);
 if (!(flags & 0x4000)) {
  if (flags & 0x800) n = 3;
  else { n = 2; if (flags & 0x400) n = 4; }
 }
 if (n != -1) {
  self->b.v8(lbl_27_rodata_4610, 4, (void*)&self->pad0[0xcc], n);
  self->b.v6(4, (void*)&self->pad0[0xcc], (float)n);
 }
 void* p = self->c.v4(0x1000001b);
 if (p) self->d.v7(p, 0, 1, 0);
}