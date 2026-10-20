#pragma force_active on
struct S { char pad[8]; unsigned int flags; };
extern "C" void fn_56_6710(S* s) { s->flags &= ~0x80000u; }
