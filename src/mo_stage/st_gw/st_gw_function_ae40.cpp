#pragma force_active on
struct S {
    int a;
    int b;
    unsigned int x : 2;
    int y : 2;
};

extern "C" int fn_63_AE40(struct S *s) {
    return s->y;
}
