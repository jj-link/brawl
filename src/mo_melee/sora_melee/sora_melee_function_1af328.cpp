#pragma force_active on
struct Entry {
    int data[3];
};

struct Object {
    char padding[0x18];
    int state;
    Entry entries[8];
};

extern "C" Entry* fn_27_1AF328(Object* object, int index) {
    int slot = (object->state >> 27) + index;
    if (slot >= 8) {
        slot -= 8;
    }
    return &object->entries[slot];
}
