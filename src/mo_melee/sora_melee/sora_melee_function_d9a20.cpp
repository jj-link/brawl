#pragma force_active on
struct Entry {
    char data[0x24];
};

struct Object {
    int unknown[2];
    int flags;
    Entry entries[9];
};

extern "C" Entry* fn_27_D9A20(Object* object, unsigned int index)
{
    int offset = (object->flags >> 27) + index;
    if (offset >= 9)
        offset -= 9;
    return &object->entries[offset];
}
