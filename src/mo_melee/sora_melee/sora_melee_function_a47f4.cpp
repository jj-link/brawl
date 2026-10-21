#pragma force_active on

struct Entry {
    unsigned char padding[4];
    int field;
};

class Array {
public:
    virtual ~Array();
    virtual Entry* get(int index);
    virtual void f4();
    virtual int size();
};

struct Object {
    unsigned char padding[0x30];
    Array* entries;
};

extern "C" bool fn_27_A47F4(Object* self, int index) {
    if (index < 0 || index >= self->entries->size())
        return false;
    return self->entries->get(index)->field != 0;
}
