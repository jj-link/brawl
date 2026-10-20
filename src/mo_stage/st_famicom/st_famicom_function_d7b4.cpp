#pragma force_active on
struct S { char pad[8]; unsigned a:12; unsigned b:1; };
extern "C" unsigned fn_68_D7B4(S* s) { return s->b; }
