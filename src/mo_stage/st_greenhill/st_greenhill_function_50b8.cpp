#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int hi : 2;
    unsigned int rest : 30;
} FnStruct;

extern "C" {
void fn_72_50B8(FnStruct *s, unsigned int v)
{
    s->hi = v;
}
}
