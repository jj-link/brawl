#pragma force_active on
struct S {
    int pad[2];
    int v;
};

extern "C" {
int fn_40_249E0(S *p)
{
    return (int)((p->v << 2) & 0xE0000000) >> 30;
}
}
