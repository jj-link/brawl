#pragma force_active on

typedef struct
{
    unsigned int pad[2];
    unsigned int top : 2;
    unsigned int rest : 30;
} BitsHolder;

extern "C" void fn_63_10AEC(BitsHolder *p, unsigned int v)
{
    p->top = v;
}
