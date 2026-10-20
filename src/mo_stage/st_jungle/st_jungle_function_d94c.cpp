#pragma force_active on
struct S { char pad[8]; int val; };
extern "C" int fn_51_D94C(S* s) { return s->val >> 29; }
