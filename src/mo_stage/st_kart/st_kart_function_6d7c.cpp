#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int f : 2;
    unsigned int rest : 30;
} S;

extern "C" void fn_49_6D7C(S *s, unsigned int v)
{
    s->f = v;
}
