#pragma force_active on
struct S { char pad[8]; int a : 3; int b : 3; };
extern "C" int fn_57_A754(S* s) { return s->b; }
