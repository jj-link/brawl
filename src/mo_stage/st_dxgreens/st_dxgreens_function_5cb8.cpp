#pragma force_active on
struct S { int a; int b; unsigned c; };
extern "C" unsigned fn_79_5CB8(S* s) {
    return (s->c >> 19) & 1;
}
