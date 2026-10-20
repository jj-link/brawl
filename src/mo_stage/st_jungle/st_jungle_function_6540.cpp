#pragma force_active on
struct Obj
{
    unsigned int pad[2];
    unsigned int flags;
};

extern "C" int fn_51_6540(Obj *obj)
{
    return (int)((obj->flags << 4) & 0xE0000000u) >> 30;
}
