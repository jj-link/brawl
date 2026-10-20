#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int f : 2;
    unsigned int rest : 28;
} S;

extern "C" void fn_62_A470(S *s, unsigned int v)
{
    s->f = v;
}
