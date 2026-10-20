#pragma force_active on
typedef struct BitStruct {
    int unk0;
    int unk4;
    unsigned int top : 4;
    unsigned int rest : 28;
} BitStruct;

extern "C" void fn_54_689C(BitStruct *p, unsigned int v)
{
    p->top = v;
}
