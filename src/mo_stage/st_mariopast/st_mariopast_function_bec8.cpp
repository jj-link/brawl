#pragma force_active on
struct S {
    int a;
    int b;
    int c;
};

extern "C" int fn_48_BEC8(S *s) {
    return (s->c >> 13) & 1;
}
