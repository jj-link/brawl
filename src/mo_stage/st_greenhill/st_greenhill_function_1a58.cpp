#pragma force_active on
struct S { char pad[0x6c]; unsigned char a:4; unsigned char b:1; unsigned char c:3; };
extern "C" void fn_72_1A58(S* s) { s->b = 0; }
