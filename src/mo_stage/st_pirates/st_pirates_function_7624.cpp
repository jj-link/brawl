#pragma force_active on
typedef struct Obj {
    int f0;
    int f4;
    unsigned int hi : 4;
    unsigned int rest : 28;
} Obj;

extern "C" void fn_52_7624(Obj *p, unsigned int v)
{
    p->hi = v;
}
