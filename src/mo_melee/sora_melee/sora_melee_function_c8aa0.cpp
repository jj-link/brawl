#pragma force_active on
struct Value {
    int a;
    int b;
    int c;
    short d;
    short e;
};

struct Entry {
    Value value;
    int padding[2];
};

struct Object {
    int header[3];
    Entry entries[1];
};

extern "C" int fn_27_C90BC(Object*, int, int);

extern "C" void fn_27_C8AA0(Object* self, int index, const Value* value) {
    int slot = fn_27_C90BC(self, index - 1, -1);
    if (slot >= 0) {
        self->entries[slot].value = *value;
    }
}
