#pragma force_active on
struct S { char pad[8]; int val; };
extern "C" int fn_47_4D9C(S* s) { return s->val >> 30; }
