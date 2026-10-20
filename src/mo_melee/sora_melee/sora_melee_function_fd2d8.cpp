#pragma force_active on
struct Entry {
    char data[12];
};

struct Object {
    char pad[0x18];
    signed int state : 3;
    unsigned int rest : 29;
    Entry entries[2];
};

extern "C" Entry* fn_27_FD2D8(Object* object, int index)
{
    int slot = object->state + index;
    if (slot >= 2)
        slot -= 2;
    return &object->entries[slot];
}
