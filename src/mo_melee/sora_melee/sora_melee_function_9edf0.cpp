#pragma force_active on
struct Value {
    int value;
    float amount;
};

struct Entry {
    Value value;
    int padding[2];
};

struct Work {
    int header[3];
    Entry entries[1];
};

extern "C" int fn_27_9F16C(Work*, int, int);

extern "C" void fn_27_9EDF0(Work* self, const Value* value) {
    int index = fn_27_9F16C(self, -1, -1);
    if (index >= 0) {
        self->entries[index].value = *value;
    }
}
