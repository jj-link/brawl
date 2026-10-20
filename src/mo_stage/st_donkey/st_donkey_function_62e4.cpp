#pragma force_active on
struct S { char pad[8]; unsigned int flags; };
extern "C" void fn_50_62E4(S* s) { s->flags &= ~0x02000000; }
