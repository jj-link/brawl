#pragma force_active on
typedef struct Obj {
    unsigned int pad[2];
    unsigned int :2;
    unsigned int f : 2;
    unsigned int :28;
} Obj;

extern "C" void fn_68_D6C0(Obj *obj, unsigned int v)
{
    obj->f = v;
}
