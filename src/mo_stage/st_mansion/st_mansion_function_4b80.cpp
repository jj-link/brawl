#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    unsigned int top : 2;
    unsigned int rest : 30;
} StObj;

extern "C" {
void fn_47_4B80(StObj *p, unsigned int v)
{
    p->top = v;
}
}
