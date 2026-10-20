#pragma force_active on
extern "C" {
struct S {
    int pad[2];
    unsigned int f : 10;
    unsigned int rest : 22;
};

void fn_27_1A6024(struct S *s, unsigned int v) {
    s->f = v;
}
}
