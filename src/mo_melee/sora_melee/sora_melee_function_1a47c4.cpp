#pragma force_active on
struct S {
    char pad[8];
    unsigned int hi : 4;
    unsigned int rest : 28;
};

extern "C" {
void fn_27_1A47C4(S* s, unsigned int v) {
    s->hi = v;
}
}
