#pragma force_active on
extern "C" {
typedef struct {
    unsigned int pad[2];
    unsigned int hi : 8;
    unsigned int f : 4;
    unsigned int lo : 20;
} BF;
}

extern "C" void fn_68_65EC(BF *p, unsigned int v)
{
    p->f = v;
}
