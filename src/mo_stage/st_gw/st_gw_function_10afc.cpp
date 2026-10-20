#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int hi : 2;
    unsigned int f : 2;
    unsigned int lo : 28;
} Flags;

extern "C" void fn_63_10AFC(Flags *p, unsigned int v)
{
    p->f = v;
}
