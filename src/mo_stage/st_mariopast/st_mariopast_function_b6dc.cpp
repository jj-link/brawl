#pragma force_active on
struct Obj
{
    unsigned char pad[8];
    unsigned int :18;
    unsigned int field : 9;
    unsigned int :5;
};

extern "C" void fn_48_B6DC(Obj *obj, unsigned int value)
{
    obj->field = value;
}
