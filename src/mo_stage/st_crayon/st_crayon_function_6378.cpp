#pragma force_active on
struct Obj
{
    unsigned int pad[2];
    unsigned int flags;
};

extern "C" void fn_56_6378(Obj* obj)
{
    obj->flags |= 0x02000000;
}
