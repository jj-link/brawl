#pragma force_active on
struct Obj
{
    unsigned int pad[27];
    unsigned int value;
};

extern "C" int fn_800F09B8(Obj* obj)
{
    return (obj->value >> 1) & 1;
}
