#pragma force_active on
struct Entry {
    int unknown;
    signed int padding : 16;
    signed int value : 16;
};

struct Array {
    virtual ~Array();
    virtual Entry& at(int index) = 0;
    virtual void unused() = 0;
    virtual int size() const = 0;
};

struct Object {
    void* unknown;
    Array* array;
};

extern "C" int fn_27_22900(Object* self) {
    int total = 0;
    for (int i = self->array->size() - 1; i >= 0; --i) {
        total += self->array->at(i).value;
    }
    return total;
}
