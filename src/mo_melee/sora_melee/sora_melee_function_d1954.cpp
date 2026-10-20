#pragma force_active on
struct fn27Bits {
    int unk0;
    int unk4;
    unsigned int top : 5;
    unsigned int rest : 27;
};

extern "C" {
void fn_27_D1954(fn27Bits *p, unsigned int v)
{
    p->top = v;
}
}
