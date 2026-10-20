#pragma force_active on
struct S { char pad[8]; unsigned int a : 2; unsigned int rest : 30; };
extern "C" void fn_77_3C78(S* s, unsigned int v) { s->a = v; }
