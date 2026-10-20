#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    unsigned int a : 8;
    unsigned int f : 4;
    unsigned int b : 20;
} FnStruct;

extern "C" {
void fn_27_1D0C40(FnStruct* p, unsigned int v)
{
    p->f = v;
}
}
