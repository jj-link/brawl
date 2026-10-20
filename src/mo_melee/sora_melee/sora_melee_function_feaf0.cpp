#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int hi : 2;
    unsigned int f : 2;
    unsigned int rest : 28;
} FooObj;

extern "C" {
void fn_27_FEAF0(FooObj* obj, unsigned int val)
{
    obj->f = val;
}
}
