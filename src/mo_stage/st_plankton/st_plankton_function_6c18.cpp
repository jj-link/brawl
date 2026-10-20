#pragma force_active on
typedef struct {
    unsigned long w0;
    unsigned long w1;
    unsigned long a : 8;
    unsigned long f : 4;
    unsigned long b : 20;
} T;

extern "C" void fn_74_6C18(T *p, unsigned long v)
{
    p->f = v;
}
