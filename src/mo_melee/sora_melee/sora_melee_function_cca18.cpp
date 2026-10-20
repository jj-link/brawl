#pragma force_active on
typedef struct {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
} FieldObj;

extern "C" void fn_27_CCA18(FieldObj *p, unsigned int v)
{
    p->b = v;
}
