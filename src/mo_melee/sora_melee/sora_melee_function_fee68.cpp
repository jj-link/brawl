#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int top : 5;
    unsigned int rest : 27;
} FeeBits;

extern "C" void fn_27_FEE68(FeeBits *p, unsigned int v)
{
    p->top = v;
}
