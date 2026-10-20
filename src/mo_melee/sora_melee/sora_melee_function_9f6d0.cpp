#pragma force_active on
struct Value {
    int word;
    float value;
};

struct Entry {
    Value data;
    int unused[2];
};

struct Object {
    int header[3];
    Entry entries[1];
};

extern "C" int fn_27_9F16C(Object*, int, int);

extern "C" void fn_27_9F6D0(Object* object, int index, const Value* value) {
    int slot = fn_27_9F16C(object, index - 1, -1);
    if (slot >= 0) {
        object->entries[slot].data = *value;
    }
}
