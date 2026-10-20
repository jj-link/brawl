#pragma force_active on
typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned int pad : 4;
    unsigned int f : 5;
} S;

extern "C" int fn_62_A688(S *s)
{
    return (int)(s->f << 27) >> 28;
}
