#pragma force_active on
struct S { char pad[8]; unsigned int a : 6; unsigned int b : 1; };
extern "C" unsigned int fn_47_4CA8(S* s) { return s->b; }
