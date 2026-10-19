#pragma force_active on
struct Fn794088Object
{
    unsigned char pad[0x1570];
    unsigned int value0;
    unsigned char gap[4];
    unsigned int value1;
};

extern "C" void fn_79_4088(Fn794088Object *object, unsigned int value0, unsigned int value1)
{
    object->value0 = value0;
    object->value1 = value1;
}
