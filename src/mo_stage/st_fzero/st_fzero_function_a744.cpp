#pragma force_active on
typedef struct S {
    int a;
    int b;
    unsigned int c;
} S;

extern "C" int fn_61_A744(S *p)
{
    unsigned int x = p->c;
    return (int)(((x << 4) | (x >> 28)) & 0xE0000000u) >> 30;
}
