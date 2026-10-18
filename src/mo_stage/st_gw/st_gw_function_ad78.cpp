#pragma force_active on
typedef struct {
    int pad[2];
    unsigned v;
} S;

extern "C" {
int fn_63_AD78(S *s)
{
    return (int)(((s->v >> 27) & 7) << 29) >> 30;
}
}
