#pragma force_active on
struct S { char pad[0x6c]; unsigned char f; };
extern "C" void fn_73_3390(S* s) { s->f &= ~0x8; }
