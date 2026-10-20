#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
} Flags;

extern "C" void fn_68_62FC(Flags *p, unsigned int v)
{
    p->b = v;
}
