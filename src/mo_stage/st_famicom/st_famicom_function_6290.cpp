#pragma force_active on
typedef struct Obj {
    int pad0;
    int pad1;
    unsigned int flags;
} Obj;

extern "C" void fn_68_6290(Obj *obj)
{
    obj->flags |= 0x02000000;
}
