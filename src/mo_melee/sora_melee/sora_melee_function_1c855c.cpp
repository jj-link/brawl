#pragma force_active on
struct Object
{
    char pad[0x18];
    int value;
};

extern "C" void *fn_27_1C855C(Object *object, int index)
{
    int field = object->value >> 26;
    int result = field + index;

    if (result >= 0x11)
        result -= 0x11;

    return (char *)object + result * 0x0C + 0x1C;
}
