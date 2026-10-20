#pragma force_active on
struct Entry {
    unsigned char padding[0x30];
    unsigned int flags;
};

struct Array {
    virtual void unused0();
    virtual Entry* at(int index);
};

struct Object {
    unsigned char padding0[0x28];
    unsigned int value;
    unsigned char padding1[0x1C];
    Array* array;
};

extern "C" bool fn_27_6A71C(Object* self, int index) {
    if (index != -1) {
        return self->array->at(index)->flags & 1;
    }
    return self->value != 0;
}
