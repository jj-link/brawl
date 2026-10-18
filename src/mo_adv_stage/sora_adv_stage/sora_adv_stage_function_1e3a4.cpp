#pragma force_active on
struct Obj
{
    unsigned int pad[2];
    unsigned int value;
};

extern "C" int fn_40_1E3A4(Obj* obj)
{
    return (obj->value >> 13) & 1;
}
