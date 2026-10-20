#pragma force_active on
typedef unsigned long u32;

typedef struct {
    u32 hi : 4;
    u32 rest : 28;
} Hdr;

extern "C" {
void fn_62_6188(Hdr *p, u32 v)
{
    p[2].hi = v;
}
}
