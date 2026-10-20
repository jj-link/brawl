#pragma force_active on
struct WorkEntry {
    unsigned int unused;
    unsigned int flags;
};

class WorkArray {
public:
    virtual ~WorkArray();
    virtual WorkEntry& at(int index);
};

struct Object {
    unsigned char padding[0x20];
    WorkArray array;
};

extern "C" void fn_27_46888(Object* self, unsigned int bit) {
    WorkEntry& entry = self->array.at(5);
    entry.flags = 1U << bit;
}
