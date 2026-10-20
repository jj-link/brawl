#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    unsigned int top : 6;
    unsigned int rest : 26;
} S;

extern "C" void fn_27_2957CC(S* p, unsigned int v)
{
    p->top = v;
}
