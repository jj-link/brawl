#pragma force_active on
typedef struct {
    unsigned int hi : 2;
    unsigned int rest : 30;
} Flags;

extern "C" void fn_47_4C48(void *p, unsigned int x)
{
    Flags *f = (Flags *)((char *)p + 8);
    f->hi = x;
}
