#pragma force_active on
struct Obj {
    int pad0;
    int pad1;
    unsigned int flags;
};

extern "C" void fn_66_A2B8(Obj *obj)
{
    obj->flags |= 0x02000000;
}
