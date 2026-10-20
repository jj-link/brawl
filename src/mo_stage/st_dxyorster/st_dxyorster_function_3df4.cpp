#pragma force_active on
struct Obj
{
    unsigned int pad[2];
    unsigned int flags;
};

extern "C" void fn_76_3DF4(Obj *obj)
{
    obj->flags |= 0x00010000u;
}
