#pragma force_active on
struct Result {
    unsigned int unused;
    unsigned int value;
};

class Interface {
public:
    virtual void unused();
    virtual Result* get();
};

struct Object {
    unsigned char padding[0x10];
    Interface interface;
};

extern "C" unsigned int fn_27_F8378(Object* object) {
    return object->interface.get()->value;
}
