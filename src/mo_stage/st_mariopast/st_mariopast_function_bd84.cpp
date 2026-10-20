#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 12;
    unsigned int b : 6;
    unsigned int c : 14;
} S;

extern "C" void fn_48_BD84(S *p, unsigned int v)
{
    p->b = v;
}
