#pragma force_active on

struct Data {
    unsigned int unused;
    unsigned int value;
};

struct Container {
    virtual void slot08();
    virtual void slot0C();
    virtual Data** at(int index);
    virtual int size();
};

struct Object {
    unsigned char unused[8];
    Container array;
};

extern "C" int fn_27_119214(Object* self, unsigned int* output) {
    int count = 0;
    int size = self->array.size();

    for (int i = 0; i < size; i++) {
        *output++ = (*self->array.at(i))->value;
        count++;
    }

    return count;
}
