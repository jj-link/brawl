#pragma force_active on
typedef struct {
    int w0;
    int w1;
    unsigned int hi : 4;
    unsigned int rest : 28;
} BitStruct;

extern "C" {
void fn_79_5C58(BitStruct *p, unsigned int v)
{
    p->hi = v;
}
}
