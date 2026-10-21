#pragma force_active on

struct Value {
    int a, b, c;
    short d, e;
};

struct Entry {
    Value value;
    int padding[2];
};

struct Object {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual int size();

    int header[2];
    Entry entries[1];
};

extern "C" int fn_27_C90BC(Object*, int, int);

extern "C" void fn_27_C89BC(Object* self, const Value* value) {
    int index = fn_27_C90BC(self, self->size() - 1, -1);
    if (index >= 0)
        self->entries[index].value = *value;
}
