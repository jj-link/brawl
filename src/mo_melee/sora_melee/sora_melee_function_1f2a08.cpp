#pragma force_active on
struct Entry { unsigned int value; unsigned char padding[16]; };
struct Object {
    union {
        struct { unsigned char padding[0x15C]; Entry entries[24]; } data;
        struct { unsigned char padding[0x32C]; bool enabled[24]; } flags;
    };
};
extern "C" void fn_27_1F2A08(Object* object, int index, unsigned int value)
{
    if (index < 0 || (unsigned int)index >= 24 || !object->flags.enabled[index])
        return;
    object->data.entries[index].value = value;
}
