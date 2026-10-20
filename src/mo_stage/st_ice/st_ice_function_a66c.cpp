#pragma force_active on
struct S { int a; int b; int c; };
extern "C" int fn_62_A66C(S* s) {
    return s->c >> 28;
}
