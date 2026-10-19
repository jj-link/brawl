#pragma force_active on
struct Element {
    int data[4];
};

struct Array {
    virtual void f0();
    virtual Element& at(int);
};

struct Obj {
    int unk0;
    Array* array;
    Element* elements;
    int offset;
};

extern "C" Element* fn_27_C76B0(Obj* self, int index) {
    if (index >= self->offset) {
        Array* array = self->array;
        if (array)
            return &array->at(index - self->offset);
    }
    return self->elements + index;
}
