#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int v;
} St;

extern "C" {
int fn_62_6198(St *p)
{
    unsigned int x = (p->v << 4) | (p->v >> 28);
    return (int)(x & 0xF8000000) >> 28;
}
}
