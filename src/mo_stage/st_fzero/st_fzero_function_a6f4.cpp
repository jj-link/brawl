#pragma force_active on
typedef struct Obj {
    int a;
    int b;
    unsigned int mode : 2;
} Obj;

extern "C" void fn_61_A6F4(Obj *p, unsigned int v)
{
    p->mode = v;
}
