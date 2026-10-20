#pragma force_active on
struct S { int a; int b; int c; };
extern "C" int fn_79_5B84(S* s) {
    return s->c >> 28;
}
