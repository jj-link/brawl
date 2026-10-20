#pragma force_active on
typedef struct {
    int a;
    int b;
    unsigned int c;
} S;

extern "C" int fn_79_5818(S *p)
{
    return ((int)(p->c << 6) & (int)0xFE000000) >> 26;
}
