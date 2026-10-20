#pragma force_active on
extern "C" {
struct S {
    int a;
    int b;
    unsigned int : 4;
    signed int f : 2;
};
int fn_62_609C(struct S *s) {
    return s->f;
}
}
