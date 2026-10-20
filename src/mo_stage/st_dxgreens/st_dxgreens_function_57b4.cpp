#pragma force_active on
typedef struct {
    int a;
    int b;
    unsigned int c;
} S79;

extern "C" int fn_79_57B4(S79 *p)
{
    unsigned int r = (p->c << 12) | (p->c >> 20);
    return ((int)(r & 0xFE000000)) >> 26;
}
