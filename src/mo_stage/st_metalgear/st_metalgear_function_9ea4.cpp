#pragma force_active on
struct S {
    int pad[2];
    unsigned int v;
};

extern "C" int fn_71_9EA4(S *p)
{
    return (int)((p->v << 2 | p->v >> 30) & 0xE0000000) >> 30;
}
