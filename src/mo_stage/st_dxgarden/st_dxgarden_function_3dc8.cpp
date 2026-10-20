#pragma force_active on
extern "C" {
typedef struct {
    unsigned int pad[2];
    unsigned int a : 8;
    unsigned int f : 4;
    unsigned int b : 20;
} Bits;

void fn_77_3DC8(Bits *p, unsigned int v)
{
    p->f = v;
}
}
