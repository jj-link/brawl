#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int w;
} St;

extern "C" {
int fn_54_67B0(St *s)
{
    return (int)(((s->w << 4) | (s->w >> 28)) & 0xE0000000) >> 30;
}
}
