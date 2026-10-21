#pragma force_active on
typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned int pad : 6;
    unsigned int f : 3;
    unsigned int rest : 23;
} Obj;

extern "C" void fn_51_D874(Obj *obj, unsigned int v)
{
    obj->f = v;
}
