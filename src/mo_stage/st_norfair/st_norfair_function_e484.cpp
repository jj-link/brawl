#pragma force_active on
struct S { int a; int b; int c; };
extern "C" int fn_54_E484(S* s) {
    return s->c >> 28;
}
