#pragma force_active on
typedef struct S {
    int pad[2];
    unsigned int f;
} S;

extern "C" int fn_79_5AA4(S *p)
{
    int t = (int)((p->f << 4) & 0xE0000000u);
    return t >> 30;
}
