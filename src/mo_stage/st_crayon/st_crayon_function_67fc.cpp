#pragma force_active on
struct S { char pad[8]; unsigned int a:8; int b:4; unsigned int c:20; };
extern "C" int fn_56_67FC(S* s) { return s->b; }
