#pragma force_active on
typedef unsigned int u32;
struct S { u32 pad[2]; unsigned int field : 4; };
extern "C" void fn_51_6854(S *p, unsigned int value) { p->field = value; }
