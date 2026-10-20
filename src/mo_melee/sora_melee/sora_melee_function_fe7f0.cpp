#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int top : 2;
    unsigned int rest : 30;
} FlagsObj;

extern "C" {
void fn_27_FE7F0(FlagsObj* p, unsigned int v)
{
    p->top = v;
}
}
