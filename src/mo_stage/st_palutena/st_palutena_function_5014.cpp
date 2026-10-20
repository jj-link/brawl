#pragma force_active on
extern "C" {
typedef struct Flags {
    unsigned int pad0 : 2;
    unsigned int f : 2;
    unsigned int rest : 28;
} Flags;

typedef struct Obj {
    unsigned int a;
    unsigned int b;
    Flags fl;
} Obj;

void fn_67_5014(Obj *o, unsigned int v)
{
    o->fl.f = v;
}
}
