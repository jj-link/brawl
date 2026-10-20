#pragma force_active on
struct S { int pad[2]; int a : 2; int b : 2; };
extern "C" int fn_78_4D60(S* s) { return s->b; }
