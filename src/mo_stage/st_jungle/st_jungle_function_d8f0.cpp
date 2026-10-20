#pragma force_active on
struct S { char pad[8]; unsigned a:9; unsigned b:1; unsigned c:22; };
extern "C" unsigned int fn_51_D8F0(S* s) { return s->b; }
