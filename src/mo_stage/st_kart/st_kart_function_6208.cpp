#pragma force_active on
struct Obj
{
    unsigned char pad[8];
    unsigned int flags;
};

extern "C" int fn_49_6208(Obj *obj)
{
    return (obj->flags >> 25) & 1;
}
