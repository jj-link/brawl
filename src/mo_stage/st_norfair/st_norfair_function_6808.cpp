#pragma force_active on
extern "C" {
typedef struct {
    unsigned int a : 2;
    unsigned int f : 2;
    unsigned int rest : 28;
} S;

void fn_54_6808(S *p, unsigned int v)
{
    p[2].f = v;
}
}
