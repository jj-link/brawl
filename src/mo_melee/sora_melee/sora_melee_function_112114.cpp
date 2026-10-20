#pragma force_active on
struct Obj
{
    char pad0[0x4C0];
    float value0;
    char pad1[0x368];
    float value1;
};

extern "C" float fn_27_112114(Obj **arg)
{
    Obj *obj = *arg;
    return obj->value0 * obj->value1;
}
