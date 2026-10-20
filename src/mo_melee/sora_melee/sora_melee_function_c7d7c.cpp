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

struct Context {
    int header[3];
    Entry entries[1];
};

extern "C" int fn_27_C8388(Context*, int, int);

extern "C" void fn_27_C7D7C(Context* self, int index, const Value* value) {
    int found = fn_27_C8388(self, index - 1, -1);
    if (found >= 0) {
        self->entries[found].value = *value;
    }
}
