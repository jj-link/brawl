#pragma force_active on
struct Entry {
    unsigned char padding[0x1D];
    unsigned char upper : 3;
    unsigned char flag : 1;
    unsigned char lower : 4;
};

struct Accessor {
    virtual void unused();
    virtual Entry* get(unsigned int index);
};

struct Object {
    unsigned char padding[0x30];
    Accessor* accessor;
};

extern "C" void fn_27_A4774(Object* object, unsigned int index, unsigned int value) {
    Entry* entry = object->accessor->get(index);
    entry->flag = value;
}
