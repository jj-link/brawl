#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int v;
} S;

extern "C" {
int fn_79_58E0(S *s)
{
    unsigned int x = s->v;
    x = (x << 6) | (x >> 26);
    x &= 0xFE000000;
    return (int)x >> 26;
}
}
