#pragma force_active on
struct S { char pad[0x184]; char a; int b; float c; };
extern "C" void fn_53_3FB4(S* s, char a, int b, float c) { s->a = a; s->b = b; s->c = c; }
