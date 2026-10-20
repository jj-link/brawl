#pragma force_active on
typedef struct Obj {
    int pad0;
    int pad1;
    unsigned int flags : 6;
    unsigned int rest : 26;
} Obj;

extern "C" void fn_48_BF24(Obj *p, unsigned int v)
{
    p->flags = v;
}
