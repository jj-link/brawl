#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int top : 5;
    unsigned int rest : 27;
} BitStruct;

extern "C" void fn_27_CB0BC(BitStruct *p, unsigned int v)
{
    p->top = v;
}
