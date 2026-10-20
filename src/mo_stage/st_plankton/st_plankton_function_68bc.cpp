#pragma force_active on
typedef unsigned int u32;

struct Object {
    u32 reserved0;
    u32 reserved1;
    u32 state;
};

extern "C" void fn_74_68BC(Object *object)
{
    object->state |= 0x02000000;
}
