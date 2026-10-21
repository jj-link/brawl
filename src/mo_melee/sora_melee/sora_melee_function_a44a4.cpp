#pragma force_active on
struct Entry {
    unsigned char padding[0x1D];
    unsigned char flag : 1;
    unsigned char unused : 7;
};

class Array {
public:
    virtual ~Array();
    virtual Entry& at(int index);
    virtual void unused();
    virtual int size();
};

struct Object {
    unsigned char padding[0x30];
    Array* entries;
};

extern "C" bool fn_27_A44A4(Object* self, int index) {
    if (index < 0 || index >= self->entries->size()) {
        return false;
    }
    return self->entries->at(index).flag;
}
