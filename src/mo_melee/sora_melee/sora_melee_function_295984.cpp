#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 12;
    unsigned int f : 6;
    unsigned int b : 14;
};

extern "C" {
void fn_27_295984(S* p, unsigned int v) {
    p->f = v;
}
}
