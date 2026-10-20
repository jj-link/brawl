#pragma force_active on
typedef unsigned int u32;
typedef struct {
    int pad[2];
    u32 a : 12;
    int b : 6;
    u32 c : 14;
} S;

extern "C" int fn_48_BD4C(S *s)
{
    return s->b;
}
