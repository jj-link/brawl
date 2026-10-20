#pragma force_active on
struct S { int a; int b; int c; int d; int e; };
extern "C" void fn_123_14120(S* s, int v) {
    s->e = v;
    s->d = v;
    s->c = v;
}
