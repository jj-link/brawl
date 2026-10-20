#pragma force_active on
typedef struct { int pad[2]; unsigned int flags; } FT;

extern "C" {
int fn_77_3D90(FT *p)
{
    unsigned int x = p->flags;
    return (int)(((x >> 19) & 0x1f) << 27) >> 28;
}
}
