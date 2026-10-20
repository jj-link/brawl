#pragma force_active on
struct S { char pad[8]; unsigned int a:12; unsigned int b:1; unsigned int c:19; };
extern "C" unsigned int fn_72_531C(S* s) { return s->b; }
