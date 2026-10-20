#pragma force_active on
typedef struct
{
    unsigned int pad[2];
    unsigned int hi : 2;
    unsigned int lo : 30;
} FnStruct;

extern "C" void fn_47_4D04(FnStruct *p, unsigned int v)
{
    p->hi = v;
}
