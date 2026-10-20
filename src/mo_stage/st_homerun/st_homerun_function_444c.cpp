#pragma force_active on
struct S { char pad[0x6c]; unsigned char flags; };
extern "C" void fn_88_444C(S* s) { s->flags |= 8; }
