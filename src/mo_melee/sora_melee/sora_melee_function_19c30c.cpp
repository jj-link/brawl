#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 4;
    unsigned int f : 2;
    unsigned int b : 26;
};

extern "C" {
void fn_27_19C30C(struct S* s, unsigned int v) {
    s->f = v;
}
}
