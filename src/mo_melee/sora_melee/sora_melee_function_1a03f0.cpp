#pragma force_active on
struct S {
    char pad[8];
    unsigned int v;
};

extern "C" {
int fn_27_1A03F0(S* s) {
    return (int)((s->v << 7) & 0xFF000000) >> 25;
}
}
