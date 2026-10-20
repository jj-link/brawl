#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int v;
} St;

extern "C" int fn_54_68AC(St *s)
{
    int t = (int)(s->v << 4);
    t &= 0xF8000000;
    return t >> 28;
}
