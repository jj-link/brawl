#pragma force_active on
struct Value {
    int a;
    int b;
    short c;
    short d;
};

struct Entry {
    Value value;
    int padding[2];
};

struct Object {
    int padding[3];
    Entry entries[1];
};

extern "C" int fn_27_2BBB0C(Object*, int, int);

extern "C" void fn_27_2BC054(Object* self, int index, const Value* value) {
    int i = fn_27_2BBB0C(self, index - 1, -1);
    if (i >= 0) {
        self->entries[i].value = *value;
    }
}
