#pragma force_active on
struct S { int a; int b; unsigned c; };
extern "C" unsigned fn_54_69C4(S* s) {
    return (s->c >> 19) & 1;
}
