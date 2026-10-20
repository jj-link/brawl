#pragma force_active on
struct Entry {
    int data[3];
};

struct Object {
    char padding[0x18];
    signed int index : 4;
    unsigned int : 28;
    Entry entries[7];
};

extern "C" Entry* fn_27_1C224C(Object* object, int index) {
    int offset = object->index + index;
    if (offset >= 7)
        offset -= 7;
    return &object->entries[offset];
}
