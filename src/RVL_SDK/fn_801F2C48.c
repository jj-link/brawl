#pragma force_active on
struct S {
    int a;
    int b;
    int c;
    unsigned int x : 8;
    unsigned int f : 24;
};

void fn_801F2C48(struct S *s, unsigned int v) {
    s->f = v >> 5;
}
