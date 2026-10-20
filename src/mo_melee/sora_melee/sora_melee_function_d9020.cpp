#pragma force_active on
struct Fn27Base {
    char pad[8];
    int field8;
};

extern "C" {
void *fn_27_D9020(Fn27Base *p, int idx)
{
    int n = (p->field8 >> 28) + idx;
    if (n >= 4) {
        n -= 4;
    }
    return (char *)p + n * 16 + 12;
}
}
