#pragma force_active on
typedef struct {
    unsigned int a : 14;
    signed int f : 7;
    unsigned int b : 11;
} S;

typedef struct {
    unsigned int w0;
    unsigned int w1;
    S s;
} T;

extern "C" {
int fn_27_CFD50(T *p)
{
    return p->s.f;
}
}
