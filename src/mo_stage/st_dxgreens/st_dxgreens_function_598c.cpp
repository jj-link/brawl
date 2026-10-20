#pragma force_active on
typedef struct Obj {
    int pad[2];
    unsigned int f : 6;
    unsigned int rest : 26;
} Obj;

extern "C" void fn_79_598C(Obj *p, unsigned int v)
{
    p->f = v;
}
