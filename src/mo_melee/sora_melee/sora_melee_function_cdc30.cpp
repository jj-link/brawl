#pragma force_active on
struct fn_27_Obj {
    unsigned int a;
    unsigned int b;
    unsigned int flags : 5;
    unsigned int rest : 27;
};

extern "C" {
void fn_27_CDC30(fn_27_Obj *obj, unsigned int v)
{
    obj->flags = v;
}
}
