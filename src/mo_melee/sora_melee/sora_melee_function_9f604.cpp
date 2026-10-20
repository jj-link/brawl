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
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int size();

    int header[2];
    Entry entries[1];
};

extern "C" int fn_27_9F16C(Object*, int, int);

extern "C" void fn_27_9F604(Object* object, const Value* value) {
    int slot = fn_27_9F16C(object, object->size() - 1, -1);
    if (slot >= 0) {
        object->entries[slot].data = *value;
    }
}
