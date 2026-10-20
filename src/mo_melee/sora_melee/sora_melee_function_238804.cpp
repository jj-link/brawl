#pragma force_active on
struct Entry {
    unsigned int flags;
    int unknown;
    int value;
    char padding[0x20];
};

struct Object {
    char padding[0x20];
    Entry* entries;
};

extern "C" void fn_27_238804(Object* object, int index, int value)
{
    if (value != object->entries[index].value) {
        object->entries[index].flags |= 1;
        object->entries[index].value = value;
    }
}
