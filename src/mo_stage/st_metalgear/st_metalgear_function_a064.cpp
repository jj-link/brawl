#pragma force_active on
typedef struct { int pad[2]; unsigned int flags; } Obj;

extern "C" {
void fn_71_A064(Obj *obj)
{
    obj->flags |= 0x02000000;
}
}
