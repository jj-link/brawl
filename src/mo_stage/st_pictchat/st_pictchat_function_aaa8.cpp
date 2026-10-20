#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int f : 2;
    unsigned int rest : 30;
} T;

extern "C" {
void fn_73_AAA8(T *p, unsigned int v)
{
    p->f = v;
}
}
