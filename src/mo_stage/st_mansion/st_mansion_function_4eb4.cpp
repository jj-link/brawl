#pragma force_active on
typedef struct {
    int pad[2];
    int v;
} S;

extern "C" int fn_47_4EB4(S *s)
{
    return ((int)((unsigned int)s->v << 4) & (int)0xE0000000) >> 30;
}
