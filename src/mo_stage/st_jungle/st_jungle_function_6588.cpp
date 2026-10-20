#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    unsigned int top : 2;
    unsigned int rest : 30;
} FnStruct;

extern "C" {
void fn_51_6588(FnStruct *p, unsigned int v)
{
    p->top = v;
}
}
