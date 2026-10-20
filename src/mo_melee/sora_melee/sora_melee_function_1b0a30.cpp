#pragma force_active on
struct Entry { char d[0x14]; };
struct S {
    char pad[8];
    int idx : 4;
    int rest : 28;
    Entry e[4];
};

extern "C" Entry* fn_27_1B0A30(S* s, int n) {
    int i = s->idx + n;
    if (i >= 4) i -= 4;
    return &s->e[i];
}
