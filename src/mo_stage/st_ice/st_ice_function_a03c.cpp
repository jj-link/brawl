#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int v;
} S;

extern "C" {
int fn_62_A03C(S *p)
{
    unsigned int r = (p->v << 2) | (p->v >> 30);
    return (int)(r & 0xE0000000) >> 30;
}
}
