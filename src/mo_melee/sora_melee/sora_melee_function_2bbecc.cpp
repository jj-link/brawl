#pragma force_active on
struct Value {
    int a;
    int b;
    short c;
    short d;
};

struct Entry {
    Value value;
    int reserved[2];
};

struct Object {
    int header[3];
    Entry entries[1];
};

extern "C" int fn_27_2BBB0C(Object*, int, int);

extern "C" void fn_27_2BBECC(Object* self, const Value* value) {
    int index = fn_27_2BBB0C(self, -1, -1);
    if (index >= 0) {
        self->entries[index].value = *value;
    }
}
