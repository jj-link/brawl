#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
} Bits;

extern "C" void fn_68_63C4(void *p, unsigned int v)
{
    ((Bits *)p)->b = v;
}
