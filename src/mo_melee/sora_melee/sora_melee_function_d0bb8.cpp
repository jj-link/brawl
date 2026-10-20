#pragma force_active on
typedef struct FnWord8
{
    int pad0;
    int pad1;
    unsigned int hi : 14;
    unsigned int f : 7;
    unsigned int lo : 11;
} FnWord8;

extern "C" {
void fn_27_D0BB8(FnWord8 *p, unsigned int v)
{
    p->f = v;
}
}
