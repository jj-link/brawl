#pragma force_active on
struct B { unsigned char pad[0x8]; float value; };
struct A { virtual void v0(); virtual B* v1(); };
struct C { unsigned char pad[0x40]; A* a; };
extern "C" float fn_27_604F0(C* self) { return self->a->v1()->value; }
