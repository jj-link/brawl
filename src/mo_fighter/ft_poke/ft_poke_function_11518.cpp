#pragma force_active on
struct S { int a, b, c, d, e; };
extern "C" void fn_116_11518(S* s, int v) {
    s->e = v;
    s->d = v;
    s->c = v;
}
