#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 18;
    unsigned int b : 9;
    unsigned int c : 5;
} T;

extern "C" void fn_27_54460(T *p, unsigned int v)
{
    p->b = v;
}
