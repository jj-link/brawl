#pragma force_active on
typedef struct Obj {
    int pad0;
    int pad1;
    unsigned int flags;
} Obj;

extern "C" void fn_48_3EEC(Obj *o)
{
    o->flags &= 0xFFF7FFFF;
}
