#pragma force_active on
typedef struct {
    char pad[8];
    unsigned int v;
} S;

extern "C" {
int fn_79_5A40(S *s)
{
    int r = (int)((s->v << 2) & 0xE0000000);
    return r >> 30;
}
}
