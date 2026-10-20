#pragma force_active on
typedef struct { int pad[2]; unsigned int w; } S;

extern "C" {
int fn_72_500C(S *p)
{
    return (int)(((p->w >> 27) & 7) << 29) >> 30;
}
}
