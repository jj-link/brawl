#pragma force_active on
struct S { char pad[8]; int a:4; int b:2; int c:26; };
extern "C" int fn_56_666C(S* s) { return s->b; }
