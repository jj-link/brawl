#pragma force_active on
extern "C" {
typedef struct {
    unsigned int header[2];
    unsigned int pad0 : 2;
    int val : 2;
    unsigned int rest : 28;
} FnStruct;

int fn_52_6F4C(FnStruct *p)
{
    return p->val;
}
}
