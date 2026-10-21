#pragma force_active on

struct S {
    char pad[8];
    unsigned f0 : 4;
    unsigned f1 : 2;
    unsigned rest : 26;
};

extern "C" void fn_77_3C68(S *s, unsigned int v) {
    s->f1 = v;
}
