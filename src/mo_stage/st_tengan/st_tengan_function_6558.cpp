#pragma force_active on
struct S { char pad[0x6c]; unsigned char flags; };
extern "C" void fn_60_6558(S* s) { s->flags |= 8; }
