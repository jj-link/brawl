#pragma force_active on
struct S { char pad[8]; int a : 2; int b : 2; };
extern "C" int fn_72_45D8(S* s) { return s->b; }
